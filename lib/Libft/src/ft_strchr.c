/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:06:31 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	SYNOPSIS: look for the first occurance contained in 'c'
**
** 	DESCRIPTION:
** 	Scan thru string 's' and look for the first char contained in 'c',
**	stop there and return the rest of the string.
*/

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

/*
int main(void)
{
	char *str = "This is MY string!";
	
	char *first_M = ft_strchr(str, 'M');
	
	printf("first_M: %s\n", first_M);
	
	char *first_Z = ft_strchr(str, 'Z');

	if (first_Z == NULL)
		printf("No 'Z' found!\n");

}
*/