/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:28:54 by vonpr             #+#    #+#             */
/*   Updated: 2026/06/15 15:30:39 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void error_msg(char *str)
{
    int i = 0;
    while (str[i])
        write(2, &str[i++], 1);
}

int cd (char **av, int i)
{
    if (i != 2)
        return (error_msg("error: cd: bad arguments\n"), 1);
    if (chdir(av[1]) == -1)
    {
        error_msg("error: cd: cannot change directory to ");
        error_msg(av[1]);
        error_msg("\n");
        return (1);   
    }
    return (0);
}

// copied the prototype
void    set_pipe(int has_pipe, int *fd, int end)
{
    // had a little check on the tasks + has pipe mistake
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == 1)) // wrong closing
        error_msg("error: fatal"), exit (1); // didn't link this case with the subject
}

// copied over the prototype here too
int    exec(char **av, int i, char **envp)
{
    int pid;
    int fd[2];
    int status;
    int has_pipe;

    has_pipe = 0;
    if (av[i] && !strcmp(av[i], "|"))
        has_pipe = 1;
    // only if there are no pipes
    if (!has_pipe && !strcmp(*av, "cd")) // pass whole av
        return(cd (av, i)); // pass av whole + return !!
    // pipe must exist
    if (has_pipe && pipe(fd) == -1)
    {
        error_msg("error: fatal"); 
        exit(1);
    }
    // condition
    if ((pid = fork()) == -1)
    {
        error_msg("error: fatal"); 
        exit(1);
    }
    if (!pid) // child process
    {
        av[i] = 0;
        set_pipe(has_pipe, fd, 1);
        // fog here
        if (!strcmp(*av, "cd"))
            exit(cd(av, i));
        // conditon & function prototype
        execve(*av, av, envp);
        error_msg("error: cannot execute "), error_msg(*av), error_msg("\n"), exit(1);
    }
    waitpid(pid, &status, 0); // terrible
    set_pipe(has_pipe, fd, 0);
    return (WIFEXITED(status) && WEXITSTATUS(status)); //OH LA D
}

// same here + arguments
int main(int, char **av, char **envp)
{
    int i;
    int status;
    int saved_stdin;

    i = 0;
    status = 0;
    saved_stdin = dup(0); // broooo
    while(av[i])
    {
        av += i + 1; // mess
        i = 0; // init i!!
        // for ";" too
        // compare with av[i] here
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (i)
            status = exec(av, i, envp);
        // check with av[i]
        if (av[i] && !strcmp(av[i], ";"))
            dup2(saved_stdin, 0); // spoiled 0
    }
    close (saved_stdin);
    return (status); // lock in broski
}
