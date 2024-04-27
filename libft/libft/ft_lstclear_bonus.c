/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:13:49 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:18:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstclear

// Prototype void ft_lstclear(t_list **lst, void (*del)(void
// *));

// Turn in files: -

// Parameters: lst: The address of a pointer to a node.
// 			   del: The address of the function used to delete
// the content of the node.

// Return value: None

// External functs.: free

// Description: Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
