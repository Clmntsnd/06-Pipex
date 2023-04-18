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

int	main()
{
	/*	Reminder : there are 3 fds by default, fd[0] (stdin), fd[1] (stdout), fd[2] (stderr)	*/
	int fd[2];
	
	int pid1;

	/*	Security, pipe() will return -1 and the variable errno set to indicate the error. */
	if (pipe(fd) == -1)
		ft_err("Pipe couldn't be created\n"); 
	
	/* Creation of another process using fork() */
	pid1 = fork();

	/*
	**	Security, fork() will return a value of -1 is returned to the parent process,
	**	no child process is created, and the global variable errno is set to indicate the error.
	*/
	if (pid1 < 0)
		ft_err("Can't fork\n");

	/*
	**	CHILD Process, if pid1 == 0, that would mean that we are 
	**	in fact in a Child process (child process,s pid are always 0)
	*/
	if (pid1 == 0)
	{
		// dup2(fd[1], STDOUT_FILENO);
		// close(fd[0]);
		// close(fd[1]);
		printf("Welcome to your Child process\n"); 
	}
	// waitpid(pid1, NULL, 0);
	printf("Welcome to Pipex\n"); //As of now, it will print twice this msg
}