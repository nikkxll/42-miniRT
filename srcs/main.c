/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/03 12:43:20 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/MLX42.h"
#include "../includes/structs.h"
#include "../includes/vec3.h"

/*
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
*/

int32_t	rgb_to_int(t_rgb3 rgb)
{
	return (rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 255);
}


void	print_picture(t_minirt *rt)
{
	int	i;
	int	j;
	int32_t color;
	t_num t;
	t_sphere *sphere;

	sphere = rt->prs->sphere;
	color = rgb_to_int(sphere->rgb);
	j = -1;
	while (++j < rt->screen.n_y)
	{
		i = -1;
		while (++i < rt->screen.n_x)
		{
			t = hit_distance_t_sphere(sphere, \
				rt->screen.rays[j * rt->screen.n_x + i]);
			if (t > EPSILON)
				mlx_put_pixel(rt->image, i, j, color);
		}
	}
}

void	ft_hook_image(void *data)
{
	t_minirt	*rt;

	rt = data;
	ft_memset(rt->image->pixels, 100, //255, //CHANNELBACK,
		rt->image->width * rt->image->height * sizeof(int32_t));
	print_picture(rt);
}

int	main(int32_t argc, char *argv[])
{
    t_minirt rt;

    (void)argv;
    (void)argc;

	// creating viewport
	t_num foc = 90;
	int	n_x = IMAGE_WIDTH;
	int n_y = IMAGE_HIGHT;
	//printf("")
	rt.screen = (t_viewport){foc, n_x, n_y, n_x * n_y, NULL};

	// creating sphere
	t_vec3d r = {0, 0, 5};
	t_rgb3	col = {200, 10, 10};
	rt.sphere = (t_sphere){0, r, 2, col, NULL};
	
	// putting sphere into parsing
	t_parse		prs;
	prs.sphere = &(rt.sphere);
	rt.prs = &prs;

	init_ray_bunch(&(rt.screen));
	rt.mlx = mlx_init(MLXWIDTH, MLXHEIGHT, "MLX42", true);
	if (!rt.mlx)
        return (1); //	ft_mlx_error(fdf, 0);
	rt.image = mlx_new_image(rt.mlx, n_x, n_y);
	if (!rt.image)
	    return (1); 	//	ft_mlx_error(fdf, 1);
	if (mlx_image_to_window(rt.mlx, rt.image, 0, 0) == -1)
		return (1); 	//ft_mlx_error(fdf, 1);
	mlx_loop_hook(rt.mlx, ft_hook_image, &rt);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	return (EXIT_SUCCESS);
}