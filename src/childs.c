/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:58:50 by csenand           #+#    #+#             */
/*   Updated: 2023/05/04 10:28:54 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_make_pids(t_data *data)
{
	int	i;

	data->pids = ft_calloc(data->cmd_nb, sizeof(pid_t *));
	if (!data->cmd_paths)
		return ;
	i = -1;
	while (++i < data->cmd_nb)
	{
		data->pids[i] = fork();
		if (data->pids[i] == -1)
			ft_err("Something went wrong during pid process:", data);
		if (data->pids[i] == 0)
			ft_child_process(data, i);
	}
	close(data->input);
	close(data->output);
	ft_close_pipes(data);
}

char	*ft_cmd_path(t_data *data, char *cmds)
{
	char	*path;
	int		i;

	if (access(cmds, X_OK | F_OK) == 0)
		return (ft_strdup(cmds));
	path = ft_strjoin("./", cmds);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	free(path);
	i = -1;
	while (data->cmd_paths[++i])
	{
		path = ft_strjoin(data->cmd_paths[i], cmds);
		if (access(path, X_OK | F_OK) == 0)
			return (path);
		free(path);
	}
	ft_err("Error ! Can't find path to program", data);
	path = NULL;
	return (path);
}

void	ft_run_cmd(t_data *data)
{
	char	*path;
	char	**cmds;
	int		i;

	cmds = ft_split(data->av[data->index + 2], ' ');
	path = ft_cmd_path(data, cmds[0]);
	if (!path)
		free(path);
	else if (execve(path, cmds, data->envp) < 0)
		ft_err("Error ! Something went wrong while executing: ", data);
	i = 0;
	while (data->cmd_paths[i])
		free(data->cmd_paths[i++]);
	free(data->cmd_paths[i++]);
	free(data->cmd_paths);
	data->cmd_paths = NULL;
}

void	ft_child_process(t_data *data, int i)
{
	data->index = i;
	if (data->index == 0)
	{
		if (data->input == -1)
		{
			ft_close_pipes(data);
			close(data->input);
			close(data->output);
			ft_err("Couldn't open the input file", data);
		}
		dup2(data->input, STDIN_FILENO);
	}
	else
		dup2(data->pipes[i - 1][0], STDIN_FILENO);
	if (data->index == data->cmd_nb - 1)
		dup2(data->output, STDOUT_FILENO);
	else
		dup2(data->pipes[i][1], STDOUT_FILENO);
	close(data->input);
	close(data->output);
	ft_close_pipes(data);
	ft_run_cmd(data);
}
