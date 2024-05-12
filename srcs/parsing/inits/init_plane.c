/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:25:20 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 18:21:03 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_bool	init_plane_params_util(char *entities[ARGS_MAX],
	char *r[ARGS_MAX], char *n[ARGS_MAX], char *rgb[ARGS_MAX])
{
	ft_bzero((void *)r, ARGS_MAX * sizeof(char *));
	ft_bzero((void *)n, ARGS_MAX * sizeof(char *));
	ft_bzero((void *)rgb, ARGS_MAX * sizeof(char *));
	if (process_args_w_commas(entities[1], r, 0) == false
		|| process_args_w_commas(entities[2], n, 0) == false
		|| process_args_w_commas(entities[3], rgb, 0) == false)
		return (false);
	if (ft_arrlen((void **)r) != VEC_LEN || ft_arrlen((void **)n) != VEC_LEN
		|| ft_arrlen((void **)rgb) != VEC_LEN)
		return (false);
	return (true);
}

static void	init_plane_params(t_plane *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char	*r[ARGS_MAX];
	char	*n[ARGS_MAX];
	char	*rgb[ARGS_MAX];

	if (init_plane_params_util(entities, r, n, rgb) == false)
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	node->r = (t_vec3d){atod_minirt(r[0], 0, 0, rt),
		atod_minirt(r[1], 0, 0, rt), atod_minirt(r[2], 0, 0, rt)};
	coord_check(node->r.x, node->r.y, node->r.z, rt);
	node->n = (t_vec3d){atod_minirt(n[0], 0, 0, rt),
		atod_minirt(n[1], 0, 0, rt), atod_minirt(n[2], 0, 0, rt)};
	orient_vec_check(node->n.x, node->n.y, node->n.z, rt);
	node->rgb = (t_rgb3){atoi_minirt(rgb[0], rt),
		atoi_minirt(rgb[1], rt), atoi_minirt(rgb[2], rt)};
	rgb_check(node->rgb.r, node->rgb.g, node->rgb.b, rt);
	init_plane_checker(node, rt, entities);
}

static t_plane	*new_plane_node(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_plane	*node;

	node = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (node)
	{
		node->type = PLANE;
		init_plane_params(node, entities, rt);
		return (node);
	}
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_pl(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_plane	*curr;

	if (!rt->prs->plane && (ft_arrlen((void **)entities) == PL_PARAMS
		|| ft_arrlen((void **)entities) == PL_PARAMS_CH))
	{
		rt->prs->plane = new_plane_node(entities, rt);
		rt->prs->plane->next = NULL;
	}
	else if (rt->prs->plane && (ft_arrlen((void **)entities) == PL_PARAMS
		|| ft_arrlen((void **)entities) == PL_PARAMS_CH))
	{
		curr = rt->prs->plane;
		while (curr->next)
			curr = curr->next;
		curr->next = new_plane_node(entities, rt);
		curr->next->next = NULL;
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	ft_printf(PRS_LOG_MSG_4);
}
