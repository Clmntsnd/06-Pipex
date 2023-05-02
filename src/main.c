//TODO 42Header

#include "../include/pipex.h"

/*
**	Parsing :
**	- It must take 4 arguments (ac == 5), as follow :
**		- ./pipex file1 cmd1 cmd2 file2
**		- file1 and file2 are file names. 
**		- cmd1 and cmd2 are shell commands with their parameters.
**
**	If you have any doubt, handle the errors like the shell command
*/

/*
**	Examples :
**	Our program should output the same result as the shell command :
**	- Pipex : ./pipex file 1 "ls -l" "wc -l" file 2
**	- shell : < file 1 ls -l | wc -l > file 2
**
**	- Pipex : ./pipex file 1 "grep a1" "wc -w" file 2
**	- shell : < file 1 ls -l | wc -l > file 2
*/

/************************************************************************/

int	main(int ac, char **av, char **envp)
{
	t_data	 *data;
	
	// if (!envp)
	// 	exit(1);
	data = NULL;
	// if(ac < 5)
	// 	ft_err("Too few arguments", data);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	ft_init_data(data, ac, av, envp);
	ft_create_pipes(data);
	ft_make_pids(data);

	// printf("Main - Pipes creation starts\n");
	// if(ft_create_pipes(data) == 0)
	// 	printf("Only one pipe\n");

	// //Printing pipe numbers per the number of cmd typed
	// int j = 0;
	// while(data->pipes[j])
	// 	printf("Pipe[%p]\n", data->pipes[j++]);
	
	printf("Main - Pipes creation ends\n");

	//Printing What's inside 'PATH' variable
	int j = 0;
	while(data->cmd_paths[j])
		printf("%s\n", data->cmd_paths[j++]);
	
	free(data);
	return (0);
}
