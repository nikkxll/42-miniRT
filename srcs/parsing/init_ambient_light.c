/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:45 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 20:39:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_aml_params(t_am_light *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char		*rgb[ARGS_MAX];

	ft_bzero((void *)rgb, ARGS_MAX * sizeof(char *));
	node->ratio = custom_atof(entities[1], 0, 0, rt);
	if (node->ratio < 0.0 || node->ratio > 1.0)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	process_args_w_commas(entities[2], rgb, 0);
	node->rgb.r = protected_atoi(rgb[0], rt);
	node->rgb.g = protected_atoi(rgb[1], rt);
	node->rgb.b = protected_atoi(rgb[2], rt);
	if (node->rgb.r < 0 || node->rgb.g < 0 || node->rgb.b < 0
		|| node->rgb.r > 255 || node->rgb.g > 255 || node->rgb.b > 255)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
}

static t_am_light	*new_aml_node(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_am_light	*node;

	node = (t_am_light *)ft_calloc(1, sizeof(t_am_light));
	if (node)
	{
		node->type = AM_LIGHT;
		init_aml_params(node, entities, rt);
		return (node);
	}
	return (NULL);
}

void	init_a(char *entities[ARGS_MAX], t_minirt *rt)
{
	if (!rt->prs->aml && ft_arrlen((void **)entities) == AL_PARAMS)
	{
		rt->prs->aml = new_aml_node(entities, rt);
		rt->prs->aml->next = NULL;
	}
	else
		generic_errors_handler(ELEM_FORMAT_ERR_MSG, ELEM_ERR, rt);
}
