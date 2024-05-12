/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:20:03 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 15:40:22 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_bool	init_light_params_util(char *entities[ARGS_MAX],
	char *r[ARGS_MAX], char *rgb[ARGS_MAX])
{
	ft_bzero((void *)r, ARGS_MAX * sizeof(char *));
	ft_bzero((void *)rgb, ARGS_MAX * sizeof(char *));
	if (process_args_w_commas(entities[1], r, 0) == false
		|| process_args_w_commas(entities[3], rgb, 0) == false)
		return (false);
	if (ft_arrlen((void **)r) != VEC_LEN || ft_arrlen((void **)rgb) != VEC_LEN)
		return (false);
	return (true);
}

static void	init_light_params(t_light *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char	*r[ARGS_MAX];
	char	*rgb[ARGS_MAX];

	if (init_light_params_util(entities, r, rgb) == false)
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	node->r.x = custom_atof(r[0], 0, 0, rt);
	node->r.y = custom_atof(r[1], 0, 0, rt);
	node->r.z = custom_atof(r[2], 0, 0, rt);
	coord_check(node->r.x, node->r.y, node->r.z, rt);
	node->brt = custom_atof(entities[2], 0, 0, rt);
	if (node->brt < 0.0 || node->brt > 1.0)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	node->rgb.r = protected_atoi(rgb[0], rt);
	node->rgb.g = protected_atoi(rgb[1], rt);
	node->rgb.b = protected_atoi(rgb[2], rt);
	rgb_check(node->rgb.r, node->rgb.g, node->rgb.b, rt);
}

static t_light	*new_light_node(char *entities[ARGS_MAX], t_minirt *rt,
	int spec)
{
	t_light	*node;

	node = (t_light *)ft_calloc(1, sizeof(t_light));
	if (node)
	{
		node->type = spec;
		init_light_params(node, entities, rt);
		return (node);
	}
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_l(char *entities[ARGS_MAX], t_minirt *rt, int spec)
{
	t_light	*curr;

	if (!rt->prs->light && ft_arrlen((void **)entities) == L_PARAMS)
	{
		rt->prs->light = new_light_node(entities, rt, spec);
		rt->prs->light->next = NULL;
	}
	else if (rt->prs->light && ft_arrlen((void **)entities) == L_PARAMS)
	{
		curr = rt->prs->light;
		while (curr->next)
			curr = curr->next;
		curr->next = new_light_node(entities, rt, spec);
		curr->next->next = NULL;
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	ft_printf(PRS_LOG_MSG_7);
}
