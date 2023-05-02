#include "../include/pipex.h"

void	ft_make_pids(t_data *data)
{
	int i;

	if (data->cmd_paths)
		return ;
	i = -1;
	while(++i < data->cmd_nb)
	{
		data->pids[i] = fork();
		if (data->pids[i] == -1)
			ft_err("Something went wrong during pid process:", data);
		
		if(data->pids[i] == 0)
			ft_child_process(data, i);
	}
	close(data->inFile);
	close(data->outFile);
}


char *ft_cmd_path(char **path, char *cmds)
{
	if (access(path, X_OK) == 0)
		return (path);
}

void	ft_run_cmd(t_data *data)
{
	char	*path;
	char	**cmd_args;

	// It splits the string at av[2] which is the cmd1 (e.g cat -e)
	cmd_args = ft_split(data->av[data->index], ' ');
	path = ft_cmd_path(data->cmd_paths, cmd_args[0]); //TODO need to implement this fct
	execve(path, cmd_args, data->envp);
}

void	ft_child_process(t_data *data, int i)
{
	dup2(data->inFile, STDIN_FILENO);
	data->index = i + 2;
	if (data->cmd_nb == 1)
	{
		dup2(data->outFile, STDOUT_FILENO);
		close(data->inFile);
		close(data->outFile);
		ft_run_cmd(data);
	}
	else
	{
		dup2(data->pipes[i][0], STDIN_FILENO);
		if (data->index == data->cmd_nb)
			dup2(data->outFile, STDOUT_FILENO);
		else
			dup2(data->pipes[i + 1][1], STDOUT_FILENO);
		close(data->inFile);
		close(data->outFile);
		data->index++;
		ft_run_cmd(data);
	}
}