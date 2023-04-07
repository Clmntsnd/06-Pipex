/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:36:05 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;
	size_t	i;

	if (!src || !dst)
		return (dst);
	c_dst = (char *) dst;
	c_src = (char *) src;
	i = 0;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (c_dst);
}

/*
int main()
{
	char src[] = "copy this";
	char dest[100];

	ft_memcpy(dest, src, strlen(src) + 1);

	printf("src : %s\n", src);
	printf("dest : %s\n", dest);	
}
*/