/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:37:32 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION
**	The ft_memchr() function locates the first occurrence of c (converted to an
**	unsigned char) in string s. Returns a pointer to the byte located, or NULL
**	if no such byte exists within n bytes.
*/

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	if (!s)
		return (NULL);
	str = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*str == ch)
			return (str);
		str++;
		i++;
	}
	return (0);
}

/*
int main()
{
	char z[] = "Hello Mate";

	char *first_c = ft_memchr(z, '\0', 11);
	
	printf("found: %s\n", first_c);
}
*/