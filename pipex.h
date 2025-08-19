/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:10:01 by diogo             #+#    #+#             */
/*   Updated: 2025/08/19 17:26:05 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "src/Libft/libft.h"

void	return_error(char *error);
void	child_proc1(char **av, char *envp[], int pipefd[]);
void	child_proc2(char **av, char *envp[], int pipefd[]);
void	exec_cmd(char *av, char *envp[]);
char	*path_finder(char *cmd, char *envp[]);
char	*path_check(char *cmd, char **paths);
void	free_array(char **s);
int		ft_wait(pid_t *proc_id);
void	close_files(int *fd, int file);
void	invalid_command(char **array, char *cmd);

#endif