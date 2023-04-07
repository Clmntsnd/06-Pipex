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

int main ()
{
	printf("Welcome to Pipex");
}