/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:20:50 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

/*
int	main(void)
{
	char	z[10];
	char	x[] = "---+--+1234ab567";
	char	y[] = "1234ab567";
	char	w[] = "\n\t -1--+--+1234ab567";

	printf("ft_atoi\n");
	printf("%d\n", ft_atoi(z));
	printf("%d\n", ft_atoi(x));
	printf("%d\n", ft_atoi(y));
	printf("%d\n", ft_atoi(w));
	printf("\n");
	printf("atoi\n");
	printf("%d\n", atoi(z));
	printf("%d\n", atoi(x));
	printf("%d\n", atoi(y));
	printf("%d\n", atoi(w));
}
*/