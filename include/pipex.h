/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:47:58 by loulou            #+#    #+#             */
/*   Updated: 2023/05/03 21:51:13 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/Libft/include/libft.h"

# define G 		"\033[1;32m"
# define R		"\033[1;31m"
# define RESET	"\033[1;0m"

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**envp;
	char	**cmd_paths;
	int		input;
	int		output;
	int		index;
	int		pipes_nb;
	int		cmd_nb;
	int		**pipes;
	pid_t	*pids;
}			t_data;

/* 		Initiate the main structure named 'data' 	*/
void	ft_init_data(t_data *data, int ac, char **av, char **envp);

/* 		Creates the required pipes					*/
int		ft_create_pipes(t_data *data);

/* 		Creates pids and childs processes			*/
void	ft_child_process(t_data *data, int i);
void	ft_make_pids(t_data *data);

/*		Close all pipes, free and error fts			*/
void	ft_close_pipes(t_data *data);
void	ft_free_data(t_data *data);
void	ft_err(char *msg, t_data *data);

#endif