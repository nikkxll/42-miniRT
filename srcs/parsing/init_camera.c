/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:56:18 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 20:28:01 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_camera_params(t_camera *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char		*r[ARGS_MAX];
	char		*n[ARGS_MAX];

	ft_bzero((void *)r, ARGS_MAX * sizeof(char *));
	ft_bzero((void *)n, ARGS_MAX * sizeof(char *));
	process_args_w_commas(entities[1], r, 0);
	node->r.x = custom_atof(r[0], 0, 0, rt);
	node->r.y = custom_atof(r[1], 0, 0, rt);
	node->r.z = custom_atof(r[2], 0, 0, rt);
	if (node->r.x > COORD_MAX || node->r.y > COORD_MAX
		|| node->r.z > COORD_MAX || node->r.x < COORD_MIN
		|| node->r.y < COORD_MIN || node->r.z < COORD_MIN)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	process_args_w_commas(entities[2], n, 0);
	node->n.x = custom_atof(n[0], 0, 0, rt);
	node->n.y = custom_atof(n[1], 0, 0, rt);
	node->n.z = custom_atof(n[2], 0, 0, rt);
	if (node->n.x > 1.0 || node->n.y > 1.0
		|| node->n.z > 1.0 || node->n.x < -1.0
		|| node->n.y < -1.0 || node->n.z < -1.0
		|| fabs(pow(node->n.x, 2) + pow(node->n.y, 2)
			+ pow(node->n.z, 2) - 1) > ROUND_PRT)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	node->fov = custom_atof(entities[3], 0, 0, rt);
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
	return (NULL);
}

void	init_c(char *entities[ARGS_MAX], t_minirt *rt)
{
	if (!rt->prs->camera && ft_arrlen((void **)entities) == C_PARAMS)
	{
		rt->prs->camera = new_camera_node(entities, rt);
		rt->prs->camera->next = NULL;
	}
	else
		generic_errors_handler(ELEM_FORMAT_ERR_MSG, ELEM_ERR, rt);
}
