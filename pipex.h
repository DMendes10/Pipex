/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:10:01 by diogo             #+#    #+#             */
/*   Updated: 2025/08/28 17:50:45 by diomende         ###   ########.fr       */
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
char	*path_finder(char *cmd, char *envp[], char **cmds);
char	*path_check(char *cmd, char **paths);
void	free_array(char **s);
int		ft_wait(pid_t *proc_id);
void	close_files(int *fd, int file);
void	invalid_command(char **array, char *cmd);
void	no_perms_command(char **array, char *cmd);
int		end_quote_check(const char *s, int i);
size_t	ft_count_words_pipex(const char *a, char c, int i);
char	*ft_makestring(const char *s, char c, size_t *i);
char	*ft_makestring_quote(const char *s, size_t *i);
char	**ft_minisplit(char **a, char const *s, char c);
char	**ft_split_pipex(char const *s, char c);
int		end_quote_check(const char *s, int i);
size_t	ft_strlcpy_quotes(char *dst, const char *src, size_t size);

#endif