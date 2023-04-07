/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:48:26 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	SYNOPSIS
**	Delete one node aliong the linked list
**
** 	DESCRIPTION
** 	Takes as a parameter a node and frees the memory of the node’s content
**	using the function ’del’ given as a parameter and free the node.
**	The memory of ’next’ must not be freed.
** 	
**	PARAMETERS
**	lst: The node to free.
**	del: The address of the function used to delete the content.
**
**	RETURN VALUE
**	None
*/

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
