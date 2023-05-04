/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:58:55 by csenand           #+#    #+#             */
/*   Updated: 2023/05/04 10:25:45 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_err(char *msg, t_data *data)
{
	ft_free_data(data);
	perror(msg);
	exit(1);
}

void	ft_free_data(t_data *data)
{
	int	i;

	if (data)
	{
		i = 0;
		if (data->cmd_paths)
		{
			while (data->cmd_paths[i])
				free(data->cmd_paths[i++]);
			free(data->cmd_paths);
			data->cmd_paths = NULL;
		}
		i = 0;
		if (data->pipes)
		{
			while (i < data->pipes_nb)
				free(data->pipes[i++]);
			free(data->pipes);
			data->pipes = NULL;
		}
		if (data->pids)
			free(data->pids);
		free(data);
	}
}

int	ft_cmd_paths_qty(char **cmd_paths)
{
	int	i;

	i = 0;
	while (cmd_paths[i])
		i++;
	return (i);
}

char	**ft_get_path(char **envp, int i)
{
	char	**cmd_paths;
	char	**new_cmd_paths;

	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
	{
		printf("coucou\n");
		new_cmd_paths = ft_calloc(1, sizeof(char *));
		new_cmd_paths[0] = ft_calloc(1, sizeof(char));
		return (new_cmd_paths);
	}
	cmd_paths = ft_split(&envp[i][5], ':');
	if (!cmd_paths)
		return (NULL);
	new_cmd_paths = ft_calloc(ft_cmd_paths_qty(cmd_paths) + 1, sizeof(char *));
	if (!new_cmd_paths)
		return (NULL);
	i = -1;
	while (cmd_paths[++i])
	{
		new_cmd_paths[i] = ft_strjoin(cmd_paths[i], "/");
		free(cmd_paths[i]);
	}
	return (free(cmd_paths), new_cmd_paths);
}

void	ft_init_data(t_data *data, int ac, char **av, char **envp)
{
	data->av = av;
	data->ac = ac;
	data->cmd_nb = ac - 3;
	data->pipes_nb = data->cmd_nb - 1;
	data->envp = envp;
	data->pipes = NULL;
	data->cmd_paths = ft_get_path(data->envp, 0);
	data->output = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	data->input = open(data->av[1], O_RDONLY);
	if (data->output == -1)
		ft_err("Error ! Couldn't create the output file", data);
}
