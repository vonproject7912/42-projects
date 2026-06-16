/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 07:51:33 by vonpr             #+#    #+#             */
/*   Updated: 2026/06/16 08:32:42 by vonpr            ###   ########.fr       */
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
        return (err("error: cd: bad arguments\n"), 1);
    if (chdir(av[1]) == -1) // focus it's only for errors
        return (err("error: cd: cannot change directory to "), err(av[1]), err("\n"), 1);
    return (0);
}

int set_pipe(int has_pipe, int *fd, int end)
{
    if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        err("error: fatal\n"), exit(1);
    return (0);
}

int exec(char **av, int i, char **envp)
{
    int pid;
    int fd[2];
    int status;
    int has_pipe;

    has_pipe = 0;
    if (av[i] && !strcmp(av[i], "|"))
        has_pipe = 1;
    if (!has_pipe && !strcmp(*av, "cd"))
        return (cd(av, i));
    if (has_pipe && pipe(fd) == -1)
        err("error: fatal\n"), exit(1);
    if ((pid = fork()) == -1)
        err("error: fatal\n"), exit(1); // exit
    if (!pid) // child process
    {
        av[i] = 0;
        set_pipe(has_pipe, fd, 1);
        if (!strcmp(*av, "cd"))
            exit(cd(av, i)); // !!
        execve(*av, av, envp);
        err("error: cannot execute "), err(av[i]), err("\n"), exit(1); // exit
    }
    waitpid(pid, &status, 0); // miiddd
    set_pipe(has_pipe, fd, 0);
    return(WIFEXITED(status) && WEXITSTATUS(status)); // switched up
}

int main(int, char **av, char **envp)
{
    int i;
    int status;
    int og_stdin;

    i = 0;
    status = 0;
    og_stdin = dup(0);
    while (av[i])
    {
        av += i + 1;
        i = 0;
        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
            i++;
        if (i)
            status = exec(av, i, envp); // get the status!!
        if (av[i] && !strcmp(av[i], ";")) // focus HARD
            dup2(og_stdin, 0);
    }
    close(og_stdin);
    return (status);
}
