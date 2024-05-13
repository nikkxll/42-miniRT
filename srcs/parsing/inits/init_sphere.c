/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:09:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/13 11:17:24 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_bool	init_sphere_params_util(char *entities[ARGS_MAX],
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

static void	init_sphere_params(t_sphere *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char	*r[ARGS_MAX];
	char	*rgb[ARGS_MAX];

	if (init_sphere_params_util(entities, r, rgb) == false)
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	node->r = (t_vec3d){atod_minirt(r[0], 0, 0, rt),
		atod_minirt(r[1], 0, 0, rt), atod_minirt(r[2], 0, 0, rt)};
	coord_check(node->r.x, node->r.y, node->r.z, rt);
	node->d = atod_minirt(entities[2], 0, 0, rt);
	if (node->d < 0.0 || node->d > ELEM_SIZE_MAX)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	node->rgb = (t_rgb3){atoi_minirt(rgb[0], rt),
		atoi_minirt(rgb[1], rt), atoi_minirt(rgb[2], rt)};
	rgb_check(node->rgb.r, node->rgb.g, node->rgb.b, rt);
	init_sphere_checker(node, rt, entities);
}

static t_sphere	*new_sphere_node(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_sphere	*node;

	node = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (node)
	{
		node->type = SPHERE;
		init_sphere_params(node, entities, rt);
		return (node);
	}
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_sp(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_sphere	*curr;

	if (!rt->prs->sphere && (ft_arrlen((void **)entities) == SP_PARAMS
			|| ft_arrlen((void **)entities) == SP_PARAMS_CH))
	{
		rt->prs->sphere = new_sphere_node(entities, rt);
		rt->prs->sphere->next = NULL;
	}
	else if (rt->prs->sphere && (ft_arrlen((void **)entities) == SP_PARAMS
			|| ft_arrlen((void **)entities) == SP_PARAMS_CH))
	{
		curr = rt->prs->sphere;
		while (curr->next)
			curr = curr->next;
		curr->next = new_sphere_node(entities, rt);
		curr->next->next = NULL;
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	ft_printf(PRS_LOG_MSG_3);
}
