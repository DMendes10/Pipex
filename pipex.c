/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:05:17 by diogo             #+#    #+#             */
/*   Updated: 2025/08/10 19:45:31 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char **av, char *envp[])
{
    int pipefd[2];
    int proc_id[2];
    int exit_code;
    
    exit_code = 1;
    if (ac == 5)
    {
        if (pipe(pipefd) < 0)
            return_error();
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
            return_error();
        exit_code = ft_wait();
    }
    else
        ft_putstr_fd ("Wrong number of parameters provided", 1);
    return (exit_code);
}

void    child_proc1(char **av, char *envp[], int pipefd[])
{
    int file1;
    
    file1 = open (av[1], O_RDONLY);
    if (file1 < 0)
    {
        close (pipefd[0]);
        close (pipefd[1]);
        return_error();
    }
    dup2(file1, STDIN_FILENO);
    dup2(pipefd[1], STDOUT_FILENO);
    close_files(file1, pipefd);
    exec_cmd(av[2], envp);
    exit (1);
}

void    child_proc2(char **av, char *envp[], int pipefd[])
{
    int file1;
    
    file1 = open (av[4], O_WRONLY | O_CREAT | O_TRUNC, 777);
    if (file1 < 0)
    {
        close (pipefd[0]);
        close (pipefd[1]);
        return_error();
    }
    dup2(pipefd[0], STDIN_FILENO);
    dup2(file1, STDOUT_FILENO);
    close_files(file1, pipefd);
    exec_cmd(av[3], envp);
    exit (1);
}

void    exec_cmd(char *cmd, char *envp[])
{
    
}