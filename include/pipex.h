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
	char	**av;
	char	**envp;
	char	**cmd_paths;
	int		inFile;
	int		outFile;
	int		pipe[2];
	pid_t	pid[2];
}			t_data;

/*
**	Parsing
*/

/*
**	Print Error message
*/
void 	ft_err(char *msg, t_data *data);
void	ft_init_data(t_data *data, int ac, char **av, char **envp);

#endif