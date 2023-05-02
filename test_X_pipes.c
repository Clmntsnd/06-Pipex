/*
**	Source : https://youtu.be/VzCawLzITh0
**	
**	Multiple pipe setup (n pipes)
**	The goal is to send from the parent process, a variable x, 
**	add 1 in a 1st child, add 1 in a 2nd child, etc ..., and send it back to the parent process.
**	
**	Reminder :
**	There is n + 1 pipes, where n is the number of processes
**	
*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

#define PROC_NB	3

int main()
{
	/*
	**	--	Pipe creation step	--
	** we'll create pipes according the nd of processes (i.e. n pipes) (pipes[PROC_NUM + 1]),
	** that has 3 std fds in each pipes (pipes[PROC_NM + 1][2]).
	*/
	int pipes[PROC_NB + 1][2]; 
	int pids[PROC_NB];
	int i;
	
	// Create the req'd nb of pipes per PROC_NB 
	i = -1; 
	while(++i < PROC_NB + 1)
		if (pipe(pipes[i]) == -1)
			printf("Something went wrong during pipe[%d] creation\n", i);

	//	--	Child processes	--
	i = -1;
	while(++i < PROC_NB)
	{
		// Create the req'd nb of childs processes (pids[i])
		pids[i] = fork();
		if (pids[i] == -1)
			printf("Something went wrong during pids[%d] process\n", i);
	
		if(pids[i] == 0)
		{
			// Close all unused pipes, in order to not leave any pipes opened for nothing
			int j;
			j = -1;
			while (++j < PROC_NB + 1)
			{
				if(i != j)
					close(pipes[j][0]);
				if(i + 1 != j)
					close(pipes[j][1]);	
			}
			
			int x;
			if(read(pipes[i][0], &x, sizeof(int)) == -1)
				printf("Child [%d] error : Couldn't read from the pipes[%d][0]\n", i, i);
			printf("Pipe[%d] got %d\n", i, x);

			// Incrementing x
			x++;
			
			if(write(pipes[i + 1][1], &x, sizeof(int)) == -1)
				printf("Child [%d] error : Couldn't write to the pipes[%d][1]\n", i, i);
			printf("Pipe[%d] sent %d\n", i, x);
			
			// Close used pipes
			close(pipes[i][0]);
			close(pipes[i + 1][1]);


			return(0);
		}
	}

	//	--	Main Porcess	--
	int y = 5; // could be any letter/name for this variable

	// Close all unused pipes, in order to not leave any pipes opened for nothing
	int j;
	j = -1;
	while (++j < PROC_NB + 1)
	{
		if(j != PROC_NB)
			close(pipes[j][0]);
		if(j != 0)
			close(pipes[j][1]);	
	}

	// Printing what the Main process sent
	printf("Main process sent %d\n", y);

	if(write(pipes[0][1], &y, sizeof(int)) == -1)
		printf("Main process error : Couldn't write to pipe[0][1]\n");
	if(read(pipes[PROC_NB][0], &y, sizeof(int)) == -1)
		printf("Parent process error : Couldn't read the pipes[2][0]\n");

	// Printing the final result (i.e what the Main process received from all the childs processes)
	printf("The final result is %d\n", y);
	
	// Close used pipes
	close(pipes[0][1]);
	close(pipes[2][0]);

	// Wait for all pids/childs to do their stuff
	i = - 1;
	while(++i < PROC_NB)
		wait(NULL);
	
	return (0);
}
