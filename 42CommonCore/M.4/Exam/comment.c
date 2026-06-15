/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 08:40:40 by vonpr             #+#    #+#             */
/*   Updated: 2026/06/15 13:11:01 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

// function that writes error messages into the fd 2
void    err(char *str)
{
    int i = 0;
    while (str[i]) // writting the error
        write (2, &str[i++], 1);
}

// cd built-in
int    cd(char **av, int i)
{
    if (i != 2) // checks the number of arguments
        return err("error: cd: bad arguments\n"), 1;
    if (chdir(av[1]) == -1) // chdir changes the program's current working directory
        return err("error: cd: cannot change directory to "), err(av[1]), err("\n"), 1;
    return 0; // check for errors otherwise return 0
}

// sets the pipe ends
void    set_pipe(int has_pipe, int *fd, int end)
{
    // if there is a pipe rewire the end to the right fd + exit on errors
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        err("error: fatal\n"), exit (1);
    // otherwise no need to rewire anything
}

// the core execution logic
int    exec(char **av, int i, char **envp)
{
    int pid; 
    int fd[2];
    int status;
    int has_pipe;
    
    has_pipe = 0; // init pipe indicator
    if (av[i] && !strcmp(av[i], "|"))
        has_pipe = 1; // check if there are any pipes
    // if there are no pipes and the command is cd
    if (!has_pipe && !strcmp(*av, "cd"))
        return (cd(av, i));
    // create the pipe before forking (<=> creating the child)
    if (has_pipe && pipe(fd) == -1) // check for errors
        err("error: fatal\n"), exit (1);
    // actually forking and creating the child
    if ((pid = fork()) == -1)
        err("error: fatal\n"), exit (1);
    if (!pid)   // child process
    {
        av[i] = 0; // null terminate '|' (since the main loop stop on '|')
        set_pipe(has_pipe, fd, 1); // wire stdout (to write)
        if (!strcmp(*av, "cd"))
            exit(cd(av, i));  // defensive case for "cd |"
            // path, arg, env
        execve(*av, av, envp); // execute 
        // case for errors
        err("error: cannot execute "), err(*av), err("\n"), exit(1);
    }
    waitpid(pid, &status, 0);
    set_pipe(has_pipe, fd, 0);
    // #1 check if the child execute normally
    // #2 get the actual exit code (0 success otherwise failure)
    return (WIFEXITED(status) && WEXITSTATUS(status));
}

// Parses and read the argument list
int main(int, char **av, char **envp)
{
    int i;
    int status;
    int saved_stdin;
    
    i = 0;
    status = 0; 
    // saves a copy of the original stdin so we can restore it after ";"
    saved_stdin = dup(0);
    while (av[i]) // loop over tokens
    {
        av += i + 1; // advance past the previous separator / program name
        i = 0;
        // scan forward to find the end of the current command segment
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (i) // execute the actual commands
            status = exec(av, i, envp);
        // check for any ";" since it breaks the any pipe chain
        if (av[i] && !strcmp(av[i], ";"))
            dup2(saved_stdin, 0);
    } 
    close (saved_stdin); // release stdin
    return status; // return the last command's exit status
}
