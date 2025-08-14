/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:05:17 by diogo             #+#    #+#             */
/*   Updated: 2025/08/14 20:02:26 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc1(char **av, char *envp[], int pipefd[])
{
	int	file1;

	file1 = open (av[1], O_RDONLY);
	if (file1 < 0)
	{
		close (pipefd[0]);
		close (pipefd[1]);
		return_error(av[1]);
	}
	dup2(file1, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close_files (pipefd, file1);
	exec_cmd(av[2], envp);
	exit (1);
}

void	child_proc2(char **av, char *envp[], int pipefd[])
{
	int	file2;

	file2 = open (av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
	{
		close (pipefd[0]);
		close (pipefd[1]);
		return_error(av[4]);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close_files (pipefd, file2);
	exec_cmd(av[3], envp);
	exit (1);
}

void	exec_cmd(char *av, char *envp[])
{
	char	*path;
	char	**cmd;

	cmd = ft_split (av, ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
	{
		invalid_command(cmd);
		exit (1);
	}
	path = path_finder(cmd[0], envp);
	if (!path)
		invalid_command (cmd);
	if (execve(path, cmd, envp) == -1)
	{
		free_array (cmd);
		if (path)
			free (path);
		return_error(av);
	}
}

char	*path_finder(char *cmd, char *envp[])
{
	char	**paths;
	int		i;

	i = 0;
	if (ft_strchr (cmd, '/') != NULL)
		return (cmd);
	if (!envp[0])
	{
		ft_putstr_fd (cmd, 2);
		ft_putstr_fd (":Command not found\n", 2);
		exit (1);
	}
	while (ft_strnstr (envp[i], "PATH", 4) == NULL)
		i++;
	if (!envp[i])
		return_error("Command not found\n");
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
		if (access (new_path, F_OK | X_OK) == 0)
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

int	ft_wait(pid_t *proc_id)
{
	int	status;
	int	exit_code;

	exit_code = 0;
	waitpid(proc_id[1], &status, 0);
	if (WIFEXITED (status))
		exit_code = WEXITSTATUS (status);
	waitpid(proc_id[0], NULL, 0);
	return (exit_code);
}

int	main(int ac, char **av, char *envp[])
{
	int		pipefd[2];
	pid_t	proc_id[2];
	int		exit_code;

	exit_code = 1;
	if (ac == 5)
	{
		if (pipe(pipefd) != 0)
			return_error("pipe error");
		proc_id[0] = fork();
		if (proc_id[0] == 0)
			child_proc1(av, envp, pipefd);
		else
		{
			proc_id[1] = fork();
			if (proc_id[1] == 0)
				child_proc2(av, envp, pipefd);
		}
		if (close(pipefd[0]) < 0 || close(pipefd[1]) < 0)
			return_error ("closing error");
		exit_code = ft_wait(proc_id);
	}
	else
		ft_putstr_fd ("Wrong number of arguments provided", 2);
	return (exit_code);
}
