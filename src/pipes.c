#include "../include/pipex.h"

int	ft_create_pipes(t_data *data)
{
	int	i;
	// int	**fd;

	// If there is only one cmd, there is no need to create a pipe
	if (data->cmd_nb < 1)
		return (0);
	
	printf("data->cmd_nb: %d\n", data->cmd_nb);
	printf("data->pipes_nb: %d\n", data->pipes_nb);

	// Allocates memory accordingly
	printf("Memory allocation starts\n");
	data->pipes = ft_calloc(data->cmd_nb, sizeof(int *));
	if (!data->pipes)
		printf("Something went wrong during calloc");
	printf("Memory allocation ends\n\n");

	printf("Pipe creation starts\n");
	printf("1st step starts\n");
	i = 0;
	while(i < data->cmd_nb)
	{	
		data->pipes[i] = ft_calloc(2, sizeof(int));
		if (!data->pipes[i])
			printf("Something went wrong during pipe creation");
			// ft_err("Something went wrong during pipe creation: ", data);
		i++;
	}
	printf("1st step ends\n");

	printf("2nd step starts\n");
	i = 0;
	while(i < data->pipes_nb)
	{
		if (pipe(data->pipes[i]) == -1)
			printf("Something went wrong during pipe creation");
			// ft_verr("Something went wrong during pipe creation: ", data);
		i++;
	}
	printf("2nd step ends\n");
	// data->pipes = fd;
	return(1);
}