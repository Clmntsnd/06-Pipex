#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int ac, char **av, char **envp)
{
	int i;
	char **tmp;
	char **paths;

	i = 0;
	tmp = envp;
	// Will increment until it finds 'PATH='
	while(ft_strncmp(tmp[i], "PATH=", 5))
		i++;
	printf("%s\n", tmp[i]);
	paths = ft_split(tmp[i], ':');
	while(paths)
		printf("%s", paths);
	return (0); 

	// printf("%s\n", tmp);
	
	// while(tmp)
	// {
	// 	printf("%s\n", tmp);
	// 	i++;
	// 	tmp = envp[i];
	// }
}