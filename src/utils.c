//TODO 42Header

#include "../include/pipex.h"

void ft_err(char *msg, t_data *data)
{
	if(data)
		free(data);
	perror(msg);
	exit(1);
}

char	**ft_get_path(char **envp)
{
	int i;
	char **cmd_paths;
	char **new_cmd_paths;

	i = 0;
	while(ft_strncmp(envp[i], "PATH=", 5))
		i++;
	cmd_paths = ft_split(&envp[i][5], ':');
	i = 0;
	while(cmd_paths[i])
		i++;		
	new_cmd_paths = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (cmd_paths[++i])
		new_cmd_paths[i] = ft_strjoin(cmd_paths[i], "/");	
	return(new_cmd_paths);
}

void	ft_init_data(t_data *data, int ac, char **av, char **envp)
{
	(void)av;
	(void)ac;
	// data->av = av;
	data->pipes_nb = ac - 2;
	data->envp = envp;

	// In this ft, we isolate the 'PATH' variable in the environment (envp)
	data->cmd_paths = ft_get_path(data->envp);
		
	// data->inFile = open(av[1], O_RDONLY);
	// if(data->inFile == -1)
	// 	ft_err("Error ! Couldn't open the input file", data);
	// data->outFile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	// if(data->outFile == -1)
	// 	ft_err("Error ! Couldn't create the output file", data);
}
