#include "../include/pipex.h"
# include <unistd.h>

void	ft_child_process(t_data *data)
{
	char	*path;
	char	**cmd_args;

	dup2(data->inFile, STDOUT_FILENO);

	path = get_cmd_path(); //TODO need to implement this fct
	cmd_args = ft_split(data->av[2], ' ');
	execve(path, cmd_args, data->envp);
}