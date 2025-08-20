/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:00:44 by diomende          #+#    #+#             */
/*   Updated: 2025/08/20 16:27:09 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char *cmd, char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
	if (ft_strchr (cmd, '/') != NULL)
		return (cmd);
	if (!envp[0])
		invalid_command (NULL, cmd);
	while (ft_strnstr (envp[i], "PATH", 4) == NULL)
		i++;
	if (!envp[i])
		invalid_command (NULL, cmd);
	paths = ft_split (envp[i] + 5, ':');
	return (path_check (cmd, paths));
}

char	*path_check(char *cmd, char **paths)
{
	int		i;
	char	*temp;
	char	*new_path;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin (paths[i], "/");
		new_path = ft_strjoin (temp, cmd);
		free (temp);
		if (access (new_path, X_OK) == 0)
		{
			free_array (paths);
			return (new_path);
		}
		free (new_path);
		i++;
	}
	free_array (paths);
	return (NULL);
}

void	free_array(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}
