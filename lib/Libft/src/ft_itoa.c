/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:44:19 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
** 	Allocates (with malloc(3)) and returns a string
** 	representing the integer received as an argument.
** 	Negative numbers must be handled.
**	
**	PARAMETERS
**	n: The integer to convert.
**	
**	RETURN VALUE
**	The string representing the integer.
**	NULL if the allocation fails.
*/

#include "../include/libft.h"

static int	num_length(long nb);

char	*ft_itoa(int n)
{
	int		i;
	char	*num_c;
	int		size;
	long	nb;

	i = 0;
	nb = n;
	size = num_length(nb);
	num_c = malloc(sizeof(char) * (size + 1));
	if (!num_c)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		num_c[0] = '-';
		i++;
	}
	num_c[size] = '\0';
	while (size != i)
	{
		size--;
		num_c[size] = nb % 10 + '0';
		nb /= 10;
	}
	return (num_c);
}

static int	num_length(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
