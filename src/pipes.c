#include "../include/pipex.h"

// void	ft_create_pipes(t_data *data)
// {
// 	// Create pipes and child processes
// 	int i;
	
// 	i = -1;
// 	while(++i < data->pipes_nb + 1)
// 		if (pipe(data->pipes[i]) == -1)
// 			ft_err("Something went wrong during pipe creation: ", data);
// 	i = -1;
// 	while(++i < data->pipes_nb)
// 	{
// 		data->pids[i] = fork();
// 		if (data->pids[i] == -1)
// 			ft_err("Something went wrong during fork process", data);
		
// 		if (data->pids[i] == 0)
// 			ft_child_process(data);
// 	}
// } 