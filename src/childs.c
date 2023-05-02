#include "../include/pipex.h"

void	ft_make_pids(t_data *data)
{
	int i;

	printf("Pids starts\n");
	data->pids = ft_calloc(data->cmd_nb, sizeof(pid_t *));
	if (!data->cmd_paths)
		return ;
	i = -1;
	// int j = 0;
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
	printf("Pids ends\n");
}


char *ft_cmd_path(t_data *data, char *cmds)
{
	char 	*path;
	int		i;

	path = ft_strdup(cmds);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	path = ft_strjoin("./", cmds);
	if (!path)
		return (NULL);
	if (access(path, X_OK | F_OK) == 0)
		return (path);
	free(path);
	i = -1;
	while(data->cmd_paths[++i])
	{
		path = ft_strjoin(data->cmd_paths[i], cmds);
		if (access(path, X_OK | F_OK) == 0)
			return (path);
		free(path);
	}
	ft_err("Error ! Can't find path to program:", data);
	return (NULL);
}

void	ft_run_cmd(t_data *data)
{
	char	*path;
	char	**cmds;

	// It splits the string at av[2] which is the cmd1 (e.g cat -e)
	cmds = ft_split(data->av[data->index + 2], ' ');
	path = ft_cmd_path(data, cmds[0]);
	if(execve(path, cmds, data->envp) < 0)
		ft_err("Error ! Something went wrong while executing: ", data);
	
}

void	ft_child_process(t_data *data, int i)
{
	printf("Child starts\n");
	data->index = i;
	if (data->cmd_nb == 1)
	{
		dup2(data->inFile, STDIN_FILENO);
		dup2(data->outFile, STDOUT_FILENO);
		close(data->inFile);
		close(data->outFile);
		ft_run_cmd(data);
		// printf("toto\n");
		// fprintf(stderr, "%s\n", "allo");
	}
	else
	{
		fprintf(stderr, "i = %d\n", i);
		if (data->index == 0)
			dup2(data->inFile, STDIN_FILENO);
		else 
			dup2(data->pipes[i - 1][0], STDIN_FILENO);
		if (data->index == data->cmd_nb - 1)
			dup2(data->outFile, STDOUT_FILENO);
		else
			dup2(data->pipes[i][1], STDOUT_FILENO);
		close(data->inFile);
		close(data->outFile);
		// ft_close_pipes(); // TODO implement this ft
		// printf("toto %d\n", i);
		ft_run_cmd(data);
		// fprintf(stderr, "%s\n", "allo 2");
	}
	// exit (127);
}