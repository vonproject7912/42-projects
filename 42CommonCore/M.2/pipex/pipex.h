/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonpr <vonpr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:09:49 by vonpr             #+#    #+#             */
/*   Updated: 2026/04/10 15:56:35 by vonpr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**paths;
	char	**envp;
	int		pipe_fd[2];
}			t_pipex;

/*       TOOLS         */
//    split
int			count_words(const char *str, char c);
int			word_len(const char *str, char c);
void		free_tab(char **tab);
char		**ft_split(char const *str, char c);

//    utils
int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);

//    errors
void		safe_closing(int fd);
void		arg_issue(t_pipex *folder);
void		error_regular_exit(char *mess);
void		error_exit_fd(char *mess, t_pipex *folder);
void		full_error(char *mess, t_pipex *folder);

/*       PIPEX        */
void		full_error_cmd2(char *mess, t_pipex *folder);
char		*find_path(char **cmd, char **envp);
void		exec_enfant_1(char *cmd, char **envp, t_pipex *folder);
void		exec_enfant_2(char *cmd, char **envp, t_pipex *folder);

// PIPEX MOUHAHAH
pid_t		enfant_1(t_pipex *folder, char *av[], char **envp);
pid_t		enfant_2(t_pipex *folder, char *av[], char **envp);
int			parent(t_pipex *folder, pid_t pid1, pid_t pid2);

#endif