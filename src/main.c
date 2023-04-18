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

// int	main()
// {
// 	/*	Reminder : there are 3 fds by default, fd[0] (stdin), fd[1] (stdout), fd[2] (stderr)	*/
// 	int fd[2];
	
// 	int pid1;

// 	/*	Security, pipe() will return -1 and the variable errno set to indicate the error. */
// 	if (pipe(fd) == -1)
// 		ft_err("Pipe couldn't be created\n"); 
	
// 	/* Creation of another process using fork() */
// 	pid1 = fork();

// 	/*
// 	**	Security, fork() will return a value of -1 is returned to the parent process,
// 	**	no child process is created, and the global variable errno is set to indicate the error.
// 	*/
// 	if (pid1 < 0)
// 		ft_err("Can't fork\n");

// 	/*
// 	**	CHILD Process, if pid1 == 0, that would mean that we are 
// 	**	in fact in a Child process (child process,s pid are always 0)
// 	*/
// 	if (pid1 == 0)
// 	{
// 		// dup2(fd[1], STDOUT_FILENO);
// 		// close(fd[0]);
// 		// close(fd[1]);
// 		printf("Welcome to your Child process\n"); 
// 	}
// 	// waitpid(pid1, NULL, 0);
// 	printf("Welcome to Pipex\n");
// }

/*
**	Source : https://youtu.be/NkfIUo_Qq4c
**	The goal is to send from the parent process, a variable x, 
**	add 5 in a 1st child, add 5 in a 2nd child, and send it back to the parent process.
**	 
** 	First we need to create a variable x and send it to the first child.
**	Then the 1st child will receive x add 5 to it, and send it to the 2nd child.
**	The 2nd child receive x + 5, and send it to the parent process.
**	The parent process will receive x + 5 + 5, and isplay it on the termninal. 
*/
int main()
{
	//	-- Pipe creation step --
	int fd[3][2]; //we'll have 3 pipes (fd[3]), that has 3 std fds in each pipes (fd[3][2]).
	int i = -1; 

	while(++i < 3)
		if (pipe(fd[i]) == -1)
			ft_err("Something went wrong during pipe creation\n");

	int pid1 = fork();
	if (pid1 == -1)
		ft_err("Something went wrong during pid 1 fork's process\n");
	
	//	-- Child process 1	--
	if(pid1 == 0)
	{
		int x;
		
		// Close all unused fd before hand, to not leave any pipes opened for nothing
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);

		if(read(fd[0][0], &x, sizeof(int)) == -1)
			ft_err("Child 1 error : Couldn't read the fd[0][0]\n");

		x += 5;
		if(write(fd[1][1], &x, sizeof(int)) == -1)
			ft_err("Child 1 error : Couldn't write to fd[1][1]\n");
		
		// Close all used fd
		close(fd[0][0]);
		close(fd[1][1]);
		return(0);
	}

	int pid2 = fork();
	if (pid2 == -1)
		ft_err("Something went wrong during pid2 fork's process\n");
	
	//	-- Child process 2	--
	if(pid2 == 0)
	{
		int x;
		
		// Close all unused fd before hand, to not leave any pipes opened for nothing
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);

		if(read(fd[1][0], &x, sizeof(int)) == -1)
			ft_err("Child 2 error : Couldn't read the fd[1][0]\n");

		x += 5;
		if(write(fd[2][1], &x, sizeof(int)) == -1)
			ft_err("Child 2 error : Couldn't write to fd[2][1]\n");
		
		// Close all used fd
		close(fd[1][0]);
		close(fd[2][1]);
		return(0);
	}

	//	--	Parent process	-- 
	int x;
	printf("Input nbr: ");
	scanf("%d", &x);

	// Close all unused fd before hand, to not leave any pipes opened for nothing
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[2][1]);

	if(write(fd[0][1], &x, sizeof(int)) == -1)
			ft_err("Parent process error : Couldn't write to fd[0][1]\n");
	
	if(read(fd[2][0], &x, sizeof(int)) == -1)
			ft_err("Parent process error : Couldn't read the fd[2][0]\n");
	//printing result
	printf("Result is %d\n", x);
	
	// Close all used fd
	close(fd[0][1]);
	close(fd[2][0]);

	// Wait for all pids to do their stuff
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
