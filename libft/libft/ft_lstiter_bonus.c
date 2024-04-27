/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:19:49 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:18:22 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstiter

// Prototype: void ft_lstiter(t_list *lst, void (*f)(void *));

// Turn in files: -

// Parameters: lst: The address of a pointer to a node.
// 			   f: The address of the function used to iterate on
// the list.

// Return value: None

// External functs.: None

// Description: Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
	{
		return ;
	}
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
