/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:51:07 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:18:30 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstmap

// Prototype: t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
// void (*del)(void *));

// Turn in files: -

// Parameters: lst: The address of a pointer to a node.
// 			   f: The address of the function used to iterate on
// the list.
// 			   del: The address of the function used to delete
// the content of a node if needed.

// Return value: The new list.
// NULL if the allocation fails.

// External functs.: malloc, free

// Description: Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*curr;
	void	*new_content;

	if (!lst || !f || !del)
		return (0);
	new = 0;
	while (lst)
	{
		new_content = f(lst->content);
		curr = ft_lstnew(new_content);
		if (!curr)
		{
			free(new_content);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, curr);
		lst = lst->next;
	}
	return (new);
}
