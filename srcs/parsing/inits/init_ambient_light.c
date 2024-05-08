/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:45 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/08 15:22:24 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_bool	init_aml_params_util(char *entities[ARGS_MAX],
	char *rgb[ARGS_MAX])
{
	ft_bzero((void *)rgb, ARGS_MAX * sizeof(char *));
	if (process_args_w_commas(entities[2], rgb, 0) == false)
		return (false);
	if (ft_arrlen((void **)rgb) != VEC_LEN)
		return (false);
	return (true);
}

static void	init_aml_params(t_am_light *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	char	*rgb[ARGS_MAX];

	if (init_aml_params_util(entities, rgb) == false)
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	node->ratio = custom_atof(entities[1], 0, 0, rt);
	if (node->ratio < EPSILON || node->ratio > 1.0)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	node->rgb.r = protected_atoi(rgb[0], rt);
	node->rgb.g = protected_atoi(rgb[1], rt);
	node->rgb.b = protected_atoi(rgb[2], rt);
	rgb_check(node->rgb.r, node->rgb.g, node->rgb.b, rt);
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
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_a(char *entities[ARGS_MAX], t_minirt *rt)
{
	if (!rt->prs->aml && ft_arrlen((void **)entities) == AL_PARAMS)
	{
		rt->prs->aml = new_aml_node(entities, rt);
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
}
