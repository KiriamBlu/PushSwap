/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:59:42 by jporta            #+#    #+#             */
/*   Updated: 2021/12/20 18:19:51 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_errorpipex(int index)
{
	if (index == 0)
	{
		ft_putstr_fd("Error dude\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	luck(char **argv, char **envp, int filein, int fileout)
{
	int	pid;
	int	fd[2];
	int status;

	if (pipe(fd) == -1)
		ft_errorpipex(0);
	pid = fork();
	if (pid == -1)
		ft_errorpipex(0);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp, 2);
		close(filein);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			exit(1);
		dup2(fileout, STDOUT_FILENO);
		execute(argv, envp, 3);
		close(fileout);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		filein;
	int		fileout;

	if (argc >= 5)
	{
		fileout = open_file(argv[argc - 1], 0);
		filein = open_file(argv[1], 1);
		dup2(filein, STDIN_FILENO);
		luck(argv, envp, filein, fileout);
	}
	else
		ft_errorpipex(0);
	return (0);
}
