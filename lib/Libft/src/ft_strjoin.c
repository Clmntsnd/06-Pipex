/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:53:56 by csenand           #+#    #+#             */
/*   Updated: 2023/04/27 14:14:48 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: concatenate two strings into a new string (with malloc)
**
** DESCRIPTION:
** 	Allocates (with malloc(3)) and returns a new string, which is the
**	result of the concatenation of ’s1’ and ’s2’.
** 
** 	PARAMETRES
** 	s1: The prefix string.
**	s2: The suffix string.
**
**	RETURN VALUE
**	The new string.
**	NULL if the allocation fails.
*/

#include "../include/libft.h"

static char	*ft_strcpy(char *dest, const char *src);

static char	*ft_strcat(char *dest, const char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	new_length;

	if (!s1 || !s2)
		return (NULL);
	new_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * new_length);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
