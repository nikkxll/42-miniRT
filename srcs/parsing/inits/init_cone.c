/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:28:35 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/13 14:46:16 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_bool	init_cone_params_util(char *entities[ARGS_MAX],
	char *r[ARGS_MAX], char *n[ARGS_MAX], char *rgb[ARGS_MAX])
{
	ft_bzero((void *)r, ARGS_MAX * sizeof(char *));
	ft_bzero((void *)n, ARGS_MAX * sizeof(char *));
	ft_bzero((void *)rgb, ARGS_MAX * sizeof(char *));
	if (process_args_w_commas(entities[1], r, 0) == false
		|| process_args_w_commas(entities[2], n, 0) == false
		|| process_args_w_commas(entities[5], rgb, 0) == false)
		return (false);
	if (ft_arrlen((void **)r) != VEC_LEN || ft_arrlen((void **)n) != VEC_LEN
		|| ft_arrlen((void **)rgb) != VEC_LEN)
		return (false);
	return (true);
}

static void	init_cone_params(t_cone *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char	*r[ARGS_MAX];
	char	*n[ARGS_MAX];
	char	*rgb[ARGS_MAX];

	if (init_cone_params_util(entities, r, n, rgb) == false)
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	node->r = (t_vec3d){atod_minirt(r[0], 0, 0, rt),
		atod_minirt(r[1], 0, 0, rt), atod_minirt(r[2], 0, 0, rt)};
	coord_check(node->r.x, node->r.y, node->r.z, rt);
	node->n = (t_vec3d){atod_minirt(n[0], 0, 0, rt),
		atod_minirt(n[1], 0, 0, rt), atod_minirt(n[2], 0, 0, rt)};
	orient_vec_check(node->n.x, node->n.y, node->n.z, rt);
	node->d = atod_minirt(entities[3], 0, 0, rt);
	if (node->d < 0.0 || node->d > ELEM_SIZE_MAX)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	node->h = atod_minirt(entities[4], 0, 0, rt);
	if (node->h < 0.0 || node->h > ELEM_SIZE_MAX)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	node->rgb = (t_rgb3){atoi_minirt(rgb[0], rt),
		atoi_minirt(rgb[1], rt), atoi_minirt(rgb[2], rt)};
	rgb_check(node->rgb.r, node->rgb.g, node->rgb.b, rt);
	init_cone_checker(node, rt, entities);
	init_cone_bump(node, rt, entities);
}

static t_cone	*new_cone_node(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_cone	*node;

	node = (t_cone *)ft_calloc(1, sizeof(t_cone));
	if (node)
	{
		node->type = CONE;
		init_cone_params(node, entities, rt);
		return (node);
	}
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_co(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_cone	*curr;

	if (!rt->prs->cone && (ft_arrlen((void **)entities) == CO_PARAMS
			|| ft_arrlen((void **)entities) == CO_PARAMS_CH
			|| ft_arrlen((void **)entities) == CO_PARAMS_BP))
	{
		rt->prs->cone = new_cone_node(entities, rt);
		rt->prs->cone->next = NULL;
	}
	else if (rt->prs->cone && (ft_arrlen((void **)entities) == CO_PARAMS
			|| ft_arrlen((void **)entities) == CO_PARAMS_CH
			|| ft_arrlen((void **)entities) == CO_PARAMS_BP))
	{
		curr = rt->prs->cone;
		while (curr->next)
			curr = curr->next;
		curr->next = new_cone_node(entities, rt);
		curr->next->next = NULL;
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	ft_printf(PRS_LOG_MSG_6);
}
