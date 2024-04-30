/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:15:43 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/30 13:43:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_am_light	*al_new_node(char **row, t_minirt *rt)
{
	t_am_light	*new_node;
	t_vec3d		vec;
	char		**rgb_split;

	rgb_split = ft_split(row[2], ',');
	if (!rgb_split)
	{
		free(row);
		free(rt);
	}
	if (ft_arrlen((void **)rgb_split) != 3)
	{
		free(row);
		free(rt);
	}
	vec.x = ft_atoi(rgb_split[0]);
	vec.y = ft_atoi(rgb_split[1]);
	vec.z = ft_atoi(rgb_split[2]);
	new_node = (t_am_light *)ft_calloc(1, sizeof(t_am_light));
	if (new_node)
	{
		new_node->ratio = ratio;
		new_node->rgb.r = ;
		new_node->next = NULL;
		return (new_node);
	}
	return (NULL);
}

void	init_ambient_lightning(char **row, t_minirt *rt)
{
	if (rt->col->aml)
		rt->col->aml = rt->col->aml->next;
	rt->col->aml = al_new_node(row, rt);
}
