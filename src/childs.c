#include "../include/pipex.h"

void	ft_child_process(t_data *data)
{
	dup2(data->inFile, STDOUT_FILENO);
}