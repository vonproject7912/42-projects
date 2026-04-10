/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:09:54 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:56:33 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// child 1: handles "< infile cmd1 |"
// redirects Stdin to the infile and Stdout to the write-end of the pipe
pid_t	enfant_1(t_pipex *folder, char *av[], char **envp)
{
	pid_t	pid1;

	// if infile couldn't be opened then don't execute
	if (folder->infile == -1)
		exit(1);
	// make the first fork = child 1
	pid1 = fork();
	if (pid1 < 0) // quick check
		full_error("fork child1 issue", folder);
	// inside the child process
	if (pid1 == 0)
	{
		// close unused read-end
		close(folder->pipe_fd[0]);
		// redirect infile -> stdin
		if (dup2(folder->infile, STDIN_FILENO) == -1)
			full_error("dup2 failed", folder);
		// redirect stdout -> pipe write-end
		if (dup2(folder->pipe_fd[1], STDOUT_FILENO) == -1)
			full_error("dup2 failed", folder);
		// close the infile
		safe_closing(folder->infile);
		// close the fd[1] we used
		close(folder->pipe_fd[1]);
		// execute the first command
		exec_enfant_1(av[2], envp, folder);
	} // return the pid of the child we created
	return (pid1);
}

// child 2: handles "| cmd2 > outfile"
// redirects Stdin to the read-end of the pipe and Stdout to the outfile
pid_t	enfant_2(t_pipex *folder, char *av[], char **envp) // same process
{
	pid_t pid2;

	// make the second fork = child 2
	pid2 = fork();
	if (pid2 < 0) // quick check
		full_error("fork child1 issue", folder);
	// inside the child process
	if (pid2 == 0)
	{
		// close unused write-end
		close(folder->pipe_fd[1]);
		// redirect pipe read-end -> stdin
		if (dup2(folder->pipe_fd[0], STDIN_FILENO) == -1)
			full_error("dup2 failed", folder);
		// redirect stdout -> outfile
		if (dup2(folder->outfile, STDOUT_FILENO) == -1)
			full_error("dup2 failed", folder);
		// close the outfile
		safe_closing(folder->outfile);
		// close the fd[0] we used
		close(folder->pipe_fd[0]);
		// execute the first command
		exec_enfant_2(av[3], envp, folder);
	} // return the pid of the child we created
	return (pid2);
}

int	parent(t_pipex *folder, pid_t pid1, pid_t pid2)
{
	int	status;
	int	exit_code;

	// parent doesn't use the pipe,
	// close both ends to avoid hangs
	close(folder->pipe_fd[0]);
	close(folder->pipe_fd[1]);
	// wait for the first child
	waitpid(pid1, NULL, 0);
	// get the status of the second child
	waitpid(pid2, &status, 0);
	// close my files
	safe_closing(folder->infile);
	safe_closing(folder->outfile);
	// extract exit code from status
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else // otherwise error
		exit_code = 1;
	return (exit_code);
}

// Main Entry: Validates arguments, sets up files, and creates the pipe
// Flow: Parse -> Open -> Pipe -> Fork1 -> Fork2 -> Parent Wait
int	main(int ac, char *av[], char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		final_exit;
	t_pipex	*folder;

	// argument check
	if (ac != 5)
		arg_issue(folder);
	// allocate where to store my data
	folder = malloc(sizeof(t_pipex));
	if (!folder)
		error_regular_exit("Folder issue");
	// open and set up the infile
	folder->infile = open(av[1], O_RDONLY);
	if (folder->infile < 0)
		perror("Couldn't open the infile");
	// open and set up the outfile
	folder->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (folder->outfile < 0)
		error_exit_fd("Couldn't open/create outfile", folder);
	// create the pipe
	if (pipe(folder->pipe_fd) == -1)
		full_error("Pipe error", folder);
	//
	pid1 = enfant_1(folder, av, envp);
	pid2 = enfant_2(folder, av, envp);
	// parent cleans up + get the exit status
	final_exit = parent(folder, pid1, pid2);
	free(folder);        // clean up
	return (final_exit); // return the exit status
}
