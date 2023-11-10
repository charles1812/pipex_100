/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:09:15 by jdecorte          #+#    #+#             */
/*   Updated: 2022/02/12 10:54:24 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getpath(char *cmd, char **allpath)
{
	int		i;
	char	*exec;
	char	**s_cmd;

	i = -1;
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		exec = ft_strjoin(ft_strjoin(allpath[i], "/"), s_cmd[0]);
		if (access(exec, F_OK | X_OK) == 0)
			break ;
		free (exec);
	}
	ft_freetab(s_cmd);
	if (access(exec, F_OK | X_OK) == 0)
		return (exec);
	return (cmd);
}

void	ft_execute(char *cmd, char **env)
{
	int		i;
	char	*path_s;
	char	**s_cmd;
	char	*path;
	char	**allpath;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path_s = &env[i][5];
		i++;
	}
	s_cmd = ft_split(cmd, ' ');
	allpath = ft_split(path_s, ':');
	path = ft_getpath(s_cmd[0], allpath);
	ft_freetab(allpath);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_freetab(s_cmd);
		exit(EXIT_FAILURE);
	}
}

void	ft_process(char **av, int *p_fd, char **env, int cmd)
{
	int		fd;

	if (cmd == 1)
		fd = open(av[1], O_RDONLY, 0444);
	if (cmd == 4)
		fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1 && cmd == 1)
	{
		dup2(fd, 0);
		dup2(p_fd[1], 1);
		close(p_fd[0]);
		ft_execute(av[2], env);
	}
	else if (fd != -1 && cmd == 4)
	{
		dup2(fd, 1);
		dup2(p_fd[0], 0);
		close(p_fd[1]);
		ft_execute(av[3], env);
	}
	perror("error : no such file");
	exit(-1);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		errno = EINVAL;
		perror("./pipex file1, cmd1, cm2, file2");
		exit(EXIT_FAILURE);
	}
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		ft_process(av, p_fd, env, 1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		ft_process(av, p_fd, env, 4);
	return (0);
}
