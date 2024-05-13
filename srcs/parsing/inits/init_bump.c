/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:39:55 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/13 16:30:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	init_cone_bump(t_cone *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	if (entities[6])
	{
		if (ft_strcmp(entities[6], "bump") == 0)
		{
			node->opt = BUMP;
			node->txr = mlx_load_png(entities[7]);
			if (!node->txr)
				generic_errors_handler(MLX_TXR_ERR_MSG, MLX_TXR_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
}

void	init_cylinder_bump(t_cylinder *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	if (entities[6])
	{
		if (ft_strcmp(entities[6], "bump") == 0)
		{
			node->opt = BUMP;
			node->txr = mlx_load_png(entities[7]);
			if (!node->txr)
				generic_errors_handler(MLX_TXR_ERR_MSG, MLX_TXR_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
}

void	init_plane_bump(t_plane *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	if (entities[4])
	{
		if (ft_strcmp(entities[4], "bump") == 0)
		{
			node->opt = BUMP;
			node->txr = mlx_load_png(entities[5]);
			if (!node->txr)
				generic_errors_handler(MLX_TXR_ERR_MSG, MLX_TXR_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
}

void	init_sphere_bump(t_sphere *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	if (entities[4])
	{
		if (ft_strcmp(entities[4], "bump") == 0)
		{
			node->opt = BUMP;
			node->txr = mlx_load_png(entities[5]);
			if (!node->txr)
				generic_errors_handler(MLX_TXR_ERR_MSG, MLX_TXR_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
}
