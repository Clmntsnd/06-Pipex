/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:05:23 by csenand           #+#    #+#             */
/*   Updated: 2023/05/03 15:08:00 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_close_pipes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->pipes_nb)
	{
		close(data->pipes[i][0]);
		close(data->pipes[i][1]);
	}
}

int	ft_create_pipes(t_data *data)
{
	int	i;

	if (data->cmd_nb < 1)
		return (0);
	data->pipes = ft_calloc(data->pipes_nb, sizeof(int *));
	if (!data->pipes)
		ft_err("Something went wrong during calloc", data);
	i = -1;
	while (++i < data->pipes_nb)
	{	
		data->pipes[i] = ft_calloc(2, sizeof(int));
		if (!data->pipes[i])
			ft_err("Something went wrong during pipe creation: ", data);
	}
	i = -1;
	while (++i < data->pipes_nb)
		if (pipe(data->pipes[i]) == -1)
			ft_err("Something went wrong during pipe creation: ", data);
	return (1);
}
