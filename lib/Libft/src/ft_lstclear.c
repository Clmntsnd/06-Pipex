/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:29:30 by csenand           #+#    #+#             */
/*   Updated: 2023/03/22 15:17:37 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
** 	Deletes and frees the given node and every successor of that node,
**	using the function ’del’ and free(3).
**	Finally, the pointer to the list must be set to NULL.	
** 	
**	PARAMETERS
**	lst: The address of a pointer to a node.
**	del: The address of the function used to delete the content of the node.
**
**	RETURN VALUE
**	None
*/

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
