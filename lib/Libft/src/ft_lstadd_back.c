/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:57:38 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
** 	Adds the node ’new’ at the end of the list.
** 	
**	PARAMETERS
**	lst: The address of a pointer to the first link of a list.
**	new: The address of a pointer to the node to be added to the list.
**
**	RETURN VALUE
**	None
*/

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add_last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	add_last = ft_lstlast(*lst);
	add_last->next = new;
}
