/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:54:29 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	SYNOPSIS
**	Add new element at beginning of list
**
** 	DESCRIPTION
** 	Adds the node ’new’ at the beginning of the list.
** 	
**	PARAMETERS
**	lst: The address of a pointer to the first link of a list.
**	new: The address of a pointer to the node to be added to the list.
**
**	RETURN VALUE
**	None.
*/

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
