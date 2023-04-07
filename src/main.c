/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:49:17 by csenand           #+#    #+#             */
/*   Updated: 2023/04/07 13:14:10 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
**	- ./pipex file 1 "ls -l" "wc -l" file 2
**	- shell : < file 1 ls -l | wc -l > file 2
**
**	- ./pipex file 1 "grep a1" "wc -w" file 2
**	- shell : < file 1 ls -l | wc -l > file 2
*/

int main ()
{
	printf("Welcome to Pipex");
}