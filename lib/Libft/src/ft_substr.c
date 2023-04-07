/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:56:40 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	SYNOPSIS: 
**	Extract substrings from string
**
** 	DESCRIPTION:
** 	Allocates (with malloc(3)) and returns a substring from the string ’s’.
**	The substring begins at index ’start’ and is of maximum size ’len’.
**	
**	PARAMETRES
**	s: The string from which to create the substring.
**	start: The start index of the substring in the string ’s’.
**	len: The maximum length of the substring.
**	
**	RETURN VALUE
**	The substring.
**	NULL if the allocation fails.
*/

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		while (s[i + start] && i < len)
			i++;
	subs = malloc(sizeof(char) * i + 1);
	if (!subs)
		return (0);
	if (start >= ft_strlen(s))
	{	
		*subs = '\0';
		return (subs);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
