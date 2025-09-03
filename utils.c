/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:00:44 by diomende          #+#    #+#             */
/*   Updated: 2025/09/03 20:07:01 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char *cmd, char *envp[], char **cmds)
{
	char	**paths;
	int		i;

	i = 0;
	if (ft_strchr (cmd, '/') != NULL)
		return (cmd);
	if (!envp[0])
		invalid_command (cmds, cmd);
	while (envp [i] && ft_strnstr (envp[i], "PATH", 4) == NULL)
		i++;
	if (!envp[i])
		invalid_command (cmds, cmd);
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

size_t	ft_count_words_pipex(const char *a, char c, int i)
{
	size_t	count;

	count = 0;
	while (a[i])
	{
		if (a[i] && a[i] != '\'' && a[i - 1] != '\'' && a[i] != c)
			count++;
		while (a[i] && a[i] != c && a[i] != '\'')
			i++;
		while (a[i] == c)
			i++;
		if (a[i] == '\'')
		{
			if (a[i - 1] == c)
				count++;
			i++;
			if (end_quote_check (a, i))
				while (a[i] != '\'')
					i++;
			else
				return (0);
			i++;
		}
	}
	return (count);
}

int	end_quote_check(const char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}
