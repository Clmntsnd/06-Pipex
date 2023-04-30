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

	/*
	**	Step 1, it increments thru the variables in the **envp until it finds 'PATH=' 
	**	then it splits the strings into several (PATH variables are separated by ':')
	** 
	**	note : envp[i] contains each 'env' variable, 'PATH', 'USER', 'PWD', etc.
	*/ 
	i = 0;
	while(ft_strncmp(envp[i], "PATH=", 5))
		i++;
	cmd_paths = ft_split(&envp[i][5], ':');

	/*
	**	Step 2, it finds the number of path variables contained in cmd_paths,
	**	then by allocating the same memory as cmd_paths, 
	**	it adds and the end of each strings a '/' (in order to add the bash cmd)
	*/
	i = 0;
	while(cmd_paths[i])
		i++;
	new_cmd_paths = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (cmd_paths[++i])
		new_cmd_paths[i] = ft_strjoin(cmd_paths[i], "/");
	free(cmd_paths);
	return(new_cmd_paths);
}

void	ft_init_data(t_data *data, int ac, char **av, char **envp)
{
	(void)av;
	// data->av = av;

	// With 2 cmds (aka processes), we need 'cmds + 1' pipes, so 3 pipes
	// I.E. with X cmds, we need 'X cmds + 1' pipes
	data->cmd_nb = ac - 3;
	data->pipes_nb = data->cmd_nb + 1;
	data->envp = envp;
	data->pipes = NULL;

	// In this ft, we isolate the 'PATH' variable in the environment (envp)
	data->cmd_paths = ft_get_path(data->envp);
		
	// data->inFile = open(av[1], O_RDONLY);
	// if(data->inFile == -1)
	// 	ft_err("Error ! Couldn't open the input file", data);
	// data->outFile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	// if(data->outFile == -1)
	// 	ft_err("Error ! Couldn't create the output file", data);
}
