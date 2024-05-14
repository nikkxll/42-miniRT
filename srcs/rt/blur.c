/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:09:25 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/14 06:48:59 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	square_init(t_num square[9][3])
{
	size_t	i;

	i = 0;
	while (i < 9)
		square[i++][0] = -1;
}

static t_vec3d	find_average(t_num square[9][3])
{
	int		counter;
	int		i;
	t_vec3d	res_vec;

	counter = 0;
	i = -1;
	res_vec = (t_vec3d){0, 0, 0};
	while (++i < 9)
	{
		if (square[i][0] != -1)
		{
			counter++;
			res_vec.x += square[i][0];
			res_vec.y += square[i][1];
			res_vec.z += square[i][2];
		}
	}
	res_vec.x /= counter;
	res_vec.y /= counter;
	res_vec.z /= counter;
	return (res_vec);
}

t_vec3d	blur(t_minirt *rt, int pos)
{
	t_num	square[9][3];
	int		new_pos;
	int		i;
	int		j;

	i = -1;
	square_init(square);
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			new_pos = pos + i * rt->vp.n_x + j;
			if (new_pos > 0 && new_pos < rt->vp.size)
			{
				square[(i + 1) * 3 + (j + 1)][0] = rt->vp.hit[new_pos].color.x;
				square[(i + 1) * 3 + (j + 1)][1] = rt->vp.hit[new_pos].color.y;
				square[(i + 1) * 3 + (j + 1)][2] = rt->vp.hit[new_pos].color.z;
			}
			j++;
		}
		i++;
	}
	return (find_average(square));
}
