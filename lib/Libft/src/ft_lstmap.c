/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:09:01 by csenand           #+#    #+#             */
/*   Updated: 2023/03/14 17:23:33 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
** 	Iterates the list ’lst’ and applies the function ’f’ on the content 
**	of each node. Creates a new list resulting of the successive applications
**	of the function ’f’. The ’del’ function is used to delete the content
**	of a node if needed.
** 	
**	PARAMETERS
**	lst: The address of a pointer to a node.
**	f: The address of the function used to iterate on the list.
**	del: The address of the function used to delete the content 
**	of a node if needed.
**
**	RETURN VALUE
**	The new list
**	NULL if the allocation fails.
*/

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
	{
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	new_lst->next = ft_lstmap(lst->next, f, del);
	return (new_lst);
}
