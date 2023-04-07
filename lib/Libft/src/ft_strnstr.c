/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:24:51 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
	i++;
	}
	return (0);
}

/*
#include <string.h>

int main()
{
    char s1[100] = "Hey mate!";
    char s2[] = "mate";

    printf("%s\n", ft_strnstr(s1, s2, 8)); 

    char s3[100] = "Hey mate!";
    char s4[] = "mate";

    printf("%s\n", strnstr(s3, s4, 8));
}
*/