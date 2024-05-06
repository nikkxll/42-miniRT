/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:09:51 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/06 12:09:10 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	rgb_check(int r, int g, int b, t_minirt *rt)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
}

void	coord_check(double x, double y, double z, t_minirt *rt)
{
	if (x > COORD_MAX || y > COORD_MAX
		|| z > COORD_MAX || x < COORD_MIN
		|| y < COORD_MIN || z < COORD_MIN)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
}

void	orient_vec_check(double x, double y, double z, t_minirt *rt)
{
	if (x == 0 && y == 0 && z == 0)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
}
