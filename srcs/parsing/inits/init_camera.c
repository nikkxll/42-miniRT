/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:56:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 18:16:39 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_bool	init_camera_params_util(char *entities[ARGS_MAX],
	char *r[ARGS_MAX], char *n[ARGS_MAX])
{
	ft_bzero((void *)r, ARGS_MAX * sizeof(char *));
	ft_bzero((void *)n, ARGS_MAX * sizeof(char *));
	if (process_args_w_commas(entities[1], r, 0) == false
		|| process_args_w_commas(entities[2], n, 0) == false)
		return (false);
	if (ft_arrlen((void **)r) != VEC_LEN || ft_arrlen((void **)n) != VEC_LEN)
		return (false);
	return (true);
}

static void	init_camera_params(t_camera *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char	*r[ARGS_MAX];
	char	*n[ARGS_MAX];

	if (init_camera_params_util(entities, r, n) == false)
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	node->r = (t_vec3d){atod_minirt(r[0], 0, 0, rt),
		atod_minirt(r[1], 0, 0, rt), atod_minirt(r[2], 0, 0, rt)};
	coord_check(node->r.x, node->r.y, node->r.z, rt);
	node->n = (t_vec3d){atod_minirt(n[0], 0, 0, rt),
		atod_minirt(n[1], 0, 0, rt), atod_minirt(n[2], 0, 0, rt)};
	orient_vec_check(node->n.x, node->n.y, node->n.z, rt);
	node->fov = atod_minirt(entities[3], 0, 0, rt);
	if (node->fov < MIN_FOV || node->fov > MAX_FOV)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
}

static t_camera	*new_camera_node(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_camera	*node;

	node = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (node)
	{
		node->type = CAMERA;
		init_camera_params(node, entities, rt);
		return (node);
	}
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_c(char *entities[ARGS_MAX], t_minirt *rt)
{
	if (!rt->prs->camera && ft_arrlen((void **)entities) == C_PARAMS)
	{
		rt->prs->camera = new_camera_node(entities, rt);
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	ft_printf(PRS_LOG_MSG_1);
}
