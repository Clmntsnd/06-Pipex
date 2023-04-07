/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:55:53 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
** 	Allocates (with malloc(3)) and returns a copy of 's1' with the characters 
**	specified in ’set’ removed from the beginning and the end of the string.
** 	
**	PARAMETERS
**	s1: The string to be trimmed.
**	set: The reference set of characters to trim
**
**	RETURN VALUE
**	The trimmed string.
**	NULL if the allocation fails.
*/

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

/*
int	main(void)
{
	char z[] = "Hello World Hello";
	//char z1[] = "ii_i__i";
	printf("Before trimming: %s\n", z);	
	
	char y[] = "Hello";
	char *trim = ft_strtrim(z, y);
	printf("Trimmed s1: %s\n", trim);
}
*/

/*
**	DETAILS
**	
**					-- 1st STEP --
**
**			while (*s1 && ft_strchr(set, *s1))
**				s1++;
**
**	-> Proto : char	*ft_strchr(const char *s, int c);
**	-> Tant que s1 existe et que strchr return qqch (i.e. valeur non NULL)
**	-> strchr prend en parametre 'set' en 1er (const char *s) 
**		car cette valeur est fixe
**	-> strchr prend en parametre '*s1' en 2eme (int c) 
** 		car cette valeur augmente avec le s++
**
**					-- 2ND STEP --
**
**			i = ft_strlen(s1);
**
**	-> on vient recuperer la longueur de s1 pour l'attribuer a i 
**
**					-- 3RD STEP -- 
**
**			while (i && ft_strchr(set, s1[i]))
**				i--;
**
**	-> Proto : char	*ft_strrchr(const char *s, int c);
**	-> Tant que i existe et que strrchr return qqch (i.e. une valeur non NULL)
**	-> strchr prend en parametre 'set' en 1er (const char *s) 
** 		car cette valeur est fixe
**	-> strchr prend en parametre 's1[i]' en 2eme (int c) 
**		car cette valeur augmente avec le s++
**	
**					-- 4TH STEP --
**
**			return (ft_substr(s1, 0, i + 1));
**
**	-> Proto : char	*ft_substr(char const *s, unsigned int start, size_t len);
**	-> on retourne une substring de s1 a partir de 0 (1er charactere) 
**		et jusqu'a i + 1, avec i etant la derniere position du parametre 'set'
**		et ensuite on ajoute '+ 1' pour faire de la place pour le '\0' 
**
*/