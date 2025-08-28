/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:28:41 by diogo             #+#    #+#             */
/*   Updated: 2025/08/27 16:51:23 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	return_error(char *error)
{
	perror (error);
	exit(1);
}

void	close_files(int *fd, int file)
{
	if (close(fd[0]) < 0 || close(fd[1]) < 0)
		return_error("closing error");
	if (close(file) < 0)
		return_error("closing error");
}

void	invalid_command(char **array, char *cmd)
{
	ft_putstr_fd (cmd, 2);
	ft_putstr_fd (": Command not found \n", 2);
	free_array (array);
	exit (127);
}

void	no_perms_command(char **array, char *cmd)
{
	ft_putstr_fd (cmd, 2);
	ft_putstr_fd (": Permission denied \n", 2);
	free_array (array);
	exit (126);
}
