/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:30:47 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/04 14:31:02 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	init_struct(t_minirt **rt)
{
	*rt = ft_calloc(1, sizeof(t_minirt));
	if (!rt)
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, *rt);
	(*rt)->prs = ft_calloc(1, sizeof(t_parse));
	if (!(*rt)->prs)
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, *rt);
	(*rt)->prs->fd = -1;
}
