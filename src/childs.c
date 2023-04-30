#include "../include/pipex.h"


// char *ft_cmd_path(char **path, char *cmds)
// {
// 	if (access(path, X_OK) == 0)
// 		return (path);
// }

// void	ft_child_process(t_data *data)
// {
// 	char	*path;
// 	char	**cmd_args;

// 	// It splits the string at av[2] which is the cmd1 (e.g cat -e)
// 	cmd_args = ft_split(data->av[2], ' ');
// 	path = ft_cmd_path(data->cmd_paths, cmd_args[0]); //TODO need to implement this fct
// 	execve(path, cmd_args, data->envp);
// }