/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:14:09 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/27 12:18:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name: ft_lstlast

// Prototype: t_list *ft_lstlast(t_list *lst);

// Turn in files: -

// Parameters: lst: The beginning of the list.

// Return value: Last node of the list

// External functs.: None

// Description: Returns the last node of the list.

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
