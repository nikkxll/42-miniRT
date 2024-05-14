/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/14 14:10:09 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_picture(t_minirt *rt)
{
	int			i;
	int			j;
	int32_t		color;

	j = -1;
	while (++j < rt->vp.size)
	{
		lighting(rt, j);
	}
	j = -1;
	while (++j < rt->vp.n_y)
	{
		i = -1;
		while (++i < rt->vp.n_x)
		{
			if (rt->prs->screen->blur == ON)
				color = rgb_to_int(vec_to_rgb(blur(rt, j * rt->vp.n_x + i)));
			else
				color = rgb_to_int(
						vec_to_rgb(rt->vp.hit[j * rt->vp.n_x + i].color));
			mlx_put_pixel(rt->image, i, j, color);
		}
	}
}

void	ft_hook_key(void *data)
{
	t_minirt	*rt;

	rt = data;
	if (mlx_is_key_down(((t_minirt *)rt)->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(((t_minirt *)rt)->mlx);
		cleaner(rt);
		exit(SUCCESS);
	}
}

int	make_picture(t_minirt *rt)
{
	ft_printf(LOG_MSG_4);
	transform_scene(rt);
	ft_printf(LOG_MSG_5);
	init_viewport(rt);
	ft_printf(LOG_MSG_6);
	hit_scene(rt);
	ft_printf(LOG_MSG_7);
	make_norm_vec(rt);
	set_checkerboard_texture(rt);
	ft_printf(LOG_MSG_8);
	rt->mlx = mlx_init(rt->prs->screen->width, rt->prs->screen->height,
			"miniRT", true);
	if (!rt->mlx)
		generic_errors_handler(MLX_ERR_MSG, MLX_ERR, rt);
	rt->image = mlx_new_image(rt->mlx, rt->vp.n_x, rt->vp.n_y);
	if (!rt->image)
		generic_errors_handler(MLX_IMG_ERR_MSG, MLX_IMG_ERR, rt);
	if (mlx_image_to_window(rt->mlx, rt->image, 0, 0) == -1)
		generic_errors_handler(MLX_IMG_W_ERR_MSG, MLX_IMG_W_ERR, rt);
	ft_printf(LOG_MSG_9);
	print_picture(rt);
	mlx_loop_hook(rt->mlx, ft_hook_key, rt);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_loop(rt->mlx);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_minirt	*rt;

	rt = NULL;
	if (ac != 2)
		generic_errors_handler(NUM_FILES_ERR_MSG, NUM_FILES_ERR, rt);
	init_struct(&rt);
	parser(av, rt);
	make_picture(rt);
	cleaner(rt);
	return (SUCCESS);
}
