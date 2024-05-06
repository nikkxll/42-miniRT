/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:31:12 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/05 11:48:57 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static void	elem_type_selection(char *ent[ARGS_MAX], t_minirt *rt)
{
	if (ent[0] && ft_strcmp(ent[0], "A") == 0)
		init_a(ent, rt);
	else if (ent[0] && ft_strcmp(ent[0], "C") == 0)
		init_c(ent, rt);
	else if (ent[0] && ft_strcmp(ent[0], "L") == 0 && !rt->prs->light)
		init_l(ent, rt, LIGHT);
	else if (ent[0] && ft_strcmp(ent[0], "l") == 0 && !rt->prs->light)
		init_l(ent, rt, MULTILIGHT);
	else if (ent[0] && ft_strcmp(ent[0], "l") == 0 && rt->prs->light
		&& rt->prs->light->type == MULTILIGHT)
		init_l(ent, rt, MULTILIGHT);
	else if (ent[0] && ((ft_strcmp(ent[0], "L") == 0 && rt->prs->light)
			|| (ft_strcmp(ent[0], "l") == 0 && rt->prs->light
				&& rt->prs->light->type == LIGHT)))
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	else if (ent[0] && ft_strcmp(ent[0], "sp") == 0)
		init_sp(ent, rt);
	else if (ent[0] && ft_strcmp(ent[0], "pl") == 0)
		init_pl(ent, rt);
	else if (ent[0] && ft_strcmp(ent[0], "cy") == 0)
		init_cy(ent, rt);
	else if (ent[0] && ft_strcmp(ent[0], "R") == 0)
		init_r(ent, rt);
}

void	init_element(t_minirt *rt)
{
	char	*entities[ARGS_MAX];

	ft_bzero((void *)entities, ARGS_MAX * sizeof(char *));
	process_args_w_sp_ht(rt->prs->line, entities, 0);
	elem_type_selection(entities, rt);
}
