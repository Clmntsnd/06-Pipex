/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:58:38 by csenand           #+#    #+#             */
/*   Updated: 2023/05/04 10:29:41 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/************************************************************************/
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
	t_data	*data;
	int		i;

	data = NULL;
	if (!(*envp))
		ft_err("No environment found", data);
	if (ac < 5)
		ft_err("Too few arguments", data);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	ft_init_data(data, ac, av, envp);
	ft_create_pipes(data);
	ft_make_pids(data);
	i = -1;
	while (++i < data->cmd_nb)
		wait(NULL);
	ft_free_data(data);
	return (0);
}
