#include "../include/pipex.h"

int	ft_create_pipes(t_data *data)
{
	int	i;
	// If there is only one cmd, there is no need to create a pipe
	if (data->cmd_nb < 1)
		return (0);
	// Allocates memory accordingly
	data->pipes = ft_calloc(data->cmd_nb, sizeof(int *));
	if (!data->pipes)
		ft_err("Something went wrong during calloc", data);
	i = -1;
	while(++i < data->cmd_nb)
	{	
		data->pipes[i] = ft_calloc(2, sizeof(int));
		if (!data->pipes[i])
			ft_err("Something went wrong during pipe creation: ", data);
	}
	i = -1;
	while(++i < data->pipes_nb)
		if (pipe(data->pipes[i]) == -1)
			ft_err("Something went wrong during pipe creation: ", data);
	return(1);
}