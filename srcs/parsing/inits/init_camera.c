/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:56:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/08 15:22:51 by apimikov         ###   ########.fr       */
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
	node->r.x = custom_atof(r[0], 0, 0, rt);
	node->r.y = custom_atof(r[1], 0, 0, rt);
	node->r.z = custom_atof(r[2], 0, 0, rt);
	coord_check(node->r.x, node->r.y, node->r.z, rt);
	node->n.x = custom_atof(n[0], 0, 0, rt);
	node->n.y = custom_atof(n[1], 0, 0, rt);
	node->n.z = custom_atof(n[2], 0, 0, rt);
	orient_vec_check(node->n.x, node->n.y, node->n.z, rt);
	node->fov = custom_atof(entities[3], 0, 0, rt);
	if (node->fov < 1 || node->fov > 179)
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
}
