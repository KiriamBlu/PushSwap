/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:34:07 by jporta            #+#    #+#             */
/*   Updated: 2021/12/20 18:19:49 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if(envp[i] == NULL)
		ft_errorpipex(0);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);	
		free(part_path);
		if (access(path, X_OK) == -1)
		{
			free(paths[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

void	execute(char **argv, char **envp, int num)
{
	char	**cmd;
	char	*pathp;

	cmd = ft_split(argv[num], ' ');
	if(cmd[0][0] == '/' | cmd[0][0] == '~' | cmd[0][0] == '.'|
		access(cmd[0], X_OK) == 0)
		if (execve(cmd[0], cmd, envp) == -1)
			ft_errorpipex(0);
	pathp = path(cmd[0], envp);
	if (execve(pathp, cmd, envp) == -1)
		ft_errorpipex(0);
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 1)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_errorpipex(0);
	return (file);
}
