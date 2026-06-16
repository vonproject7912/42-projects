/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 06:56:42 by vonpr             #+#    #+#             */
/*   Updated: 2026/06/16 07:47:29 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void err(char *str)
{
    int i = 0;
    while (str[i])
        write(2, &str[i++], 1);
}

int cd(char **av, int i)
{
    if (i != 2)
        return(err("error: cd: bad arguments\n"), 1);
    if (chdir(av[1]) == -1)
        return (err("error: cd: cannot change directory to "), err(av[1]), err("\n"), 1);
    return (0);
}

int set_pipe(int has_pipe, int *fd, int end) // Two fd so *fd
{
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        err("error: fatal\n"), exit(1);
    return (0);
}

int exec(char **av, int i, char **envp)
{
    int pid;
    int fd[2];
    int status; // don't forget it
    int has_pipe;

    // status = 0;
    has_pipe = 0;
    if (av[i] && !strcmp(av[i], "|"))
        has_pipe = 1;
    if (!has_pipe && !strcmp(*av, "cd"))  // pass av whoooolllleeee
        return (cd(av, i));
    if (has_pipe && pipe(fd) == -1)
        err("error: fatal\n"), exit (1);
    if ((pid = fork()) == -1)
        err("error: fatal\n"), exit (1);
    if (!pid) // child process
    {
        av[i] = 0;
        set_pipe(has_pipe, fd, 1); // ...
        if (!strcmp(*av, "cd")) // forgotten ++ pass it whole
            exit(cd(av, i)); // faaahhhh
        execve(*av, av, envp); // confidence
        err("error: cannot execute "), err(*av), err("\n"), exit(1); // err here
    }
    waitpid(pid, &status, 0); // 3 arguments
    set_pipe(has_pipe, fd, 0); // set pipe for the parent too broo
    return(WIFEXITED(status) && WEXITSTATUS(status)); // forgotten hard
}

int main(int, char **av, char **envp) // wth
{
    int i; // here
    int status;
    int saved_stdin;

    i = 0;
    status = 0;
    saved_stdin = dup(0);
    while(av[i])
    {
        av += i + 1;
        i = 0; // stupiiiidd av[i]
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (i)
            status = exec(av, i, envp);
        if (av[i] && !strcmp(av[i], ";")) // big hint here + av[i]
            dup2(saved_stdin, 0); // given
    }
    // hinted
    close (saved_stdin);
    return (status);
}
