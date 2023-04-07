/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:58:06 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ucb;

	i = 0;
	if (!b)
		return (NULL);
	ucb = (unsigned char *)b;
	while (i < len)
	{
		ucb[i] = c;
		i++;
	}
	return (b = ucb);
}

/*
int main()
{
	char str[30] = "ABCD EFGH";  
     
    printf("Before memset => %s",str);  
     
    ft_memset(str,'x',3);  
     
    printf("\nAfter memset => %s\n",str);  
     
    return 0;
}
*/
