/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:49:17 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 15:58:19 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static void	print_warning(char *msg)
{
	ft_printf(ORANGE);
	ft_printf(msg);
	ft_printf(EC);
}

static void	init_screen_params(t_screen *node, char *entities[ARGS_MAX],
	t_minirt *rt)
{
	node->width = protected_atoi(entities[1], rt);
	node->height = protected_atoi(entities[2], rt);
	if (node->width < VP_SIZE_MIN || node->width > VP_SIZE_MAX
		|| node->height < VP_SIZE_MIN || node->height > VP_SIZE_MAX)
	{
		node->width = VP_WIDTH_DEFAULT;
		node->height = VP_HEIGHT_DEFAULT;
		print_warning(LOG_MSG_3);
	}
	if (entities[3])
	{
		if (ft_strcmp(entities[3], "antialiasing") == 0)
			node->a = 1;
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
		print_warning(PRS_LOG_MSG_10);
	}
	else
		print_warning(PRS_LOG_MSG_9);
}

static t_screen	*new_screen_node(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_screen	*node;

	node = (t_screen *)ft_calloc(1, sizeof(t_screen));
	if (node)
	{
		node->type = VIEWPORT;
		init_screen_params(node, entities, rt);
		return (node);
	}
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_r(char *entities[ARGS_MAX], t_minirt *rt)
{
	if (!rt->prs->screen && (ft_arrlen((void **)entities) == VP_PARAMS
		|| ft_arrlen((void **)entities) == VP_PARAMS_OPT))
	{
		rt->prs->screen = new_screen_node(entities, rt);
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	ft_printf(PRS_LOG_MSG_8);
}
