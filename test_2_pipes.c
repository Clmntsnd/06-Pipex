# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>


int main()
{
	//	-- Pipe creation step --
	int fd[3][2]; //we'll have 3 pipes (fd[3]), that has 3 std fds in each pipes (fd[3][2]).
	int i = -1; 

	while(++i < 3)
		if (pipe(fd[i]) == -1)
			printf("Something went wrong during pipe creation\n");

	int pid1 = fork();
	if (pid1 == -1)
		printf("Something went wrong during pid 1 fork's process\n");
	
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
			printf("Child 1 error : Couldn't read the fd[0][0]\n");

		x += 5;
		if(write(fd[1][1], &x, sizeof(int)) == -1)
			printf("Child 1 error : Couldn't write to fd[1][1]\n");
		
		// Close all used fd
		close(fd[0][0]);
		close(fd[1][1]);
		return(0);
	}

	int pid2 = fork();
	if (pid2 == -1)
		printf("Something went wrong during pid2 fork's process\n");
	
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
			printf("Child 2 error : Couldn't read the fd[1][0]\n");

		x += 5;
		if(write(fd[2][1], &x, sizeof(int)) == -1)
			printf("Child 2 error : Couldn't write to fd[2][1]\n");
		
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
			printf("Parent process error : Couldn't write to fd[0][1]\n");
	
	if(read(fd[2][0], &x, sizeof(int)) == -1)
			printf("Parent process error : Couldn't read the fd[2][0]\n");
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