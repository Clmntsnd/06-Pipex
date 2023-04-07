/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:43:37 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**						* ft_memcpy vs ft_memmove *
**	ft_memmove can handle overlapping destination and source blocks of memory
**	whereas for ft_memecpy if the destination and source of memory overlap 
**	the behavior is undefined
**
**	If we're not sure whether or not the dest ans src blocks of memory 
**	will overlap then we should use ft_memmove because it's guaranteed 
**	to be safe.
*/

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	c_src = (char *)src;
	c_dst = (char *)dst;
	if (!c_src || !c_dst)
		return (NULL);
	if (c_dst > c_src)
	{
		while (len > 0)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(c_dst, c_src, len);
	}
	return (dst);
}

/*
int main()
{
	char src[] = "copy this";
	char dest[100];

	ft_memmove(dest, src, 6);

	printf("src : %s\n", src);
	printf("dest : %s\n", dest);

	char src1[] = "copy this";
	char dest1[100];

	memmove(src1 + 2, src1, 7);

	printf("src1 : %s\n", src1);
	printf("dest1 : %s\n", dest1);

}
*/