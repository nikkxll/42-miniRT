/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 00:31:54 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void print_ll(t_minirt *rt)
{
	if (rt->prs->screen)
	{
		printf("VIEWPORT %d   %d   %d\n", rt->prs->screen->type,
			rt->prs->screen->width, rt->prs->screen->height);
	}
	printf("AML %d   %f   %d   %d   %d\n", rt->prs->aml->type,
		rt->prs->aml->ratio, rt->prs->aml->rgb.r, rt->prs->aml->rgb.g,
		rt->prs->aml->rgb.b);
	printf("CAMERA %d   %f   %f   %f   %f   %f   %f   %f\n", rt->prs->camera->type,
		rt->prs->camera->r.x, rt->prs->camera->r.y, rt->prs->camera->r.z,
		rt->prs->camera->n.x, rt->prs->camera->n.y, rt->prs->camera->n.z,
		rt->prs->camera->fov);
	while (rt->prs->cylinder)
	{
		printf("CYLINDER %d   %f   %f   %f   %f   %f   %f   %f   %f   %i   %i   %i\n", rt->prs->cylinder->type,
		rt->prs->cylinder->r.x, rt->prs->cylinder->r.y, rt->prs->cylinder->r.z,
		rt->prs->cylinder->n.x, rt->prs->cylinder->n.y, rt->prs->cylinder->n.z,
		rt->prs->cylinder->d, rt->prs->cylinder->h, rt->prs->cylinder->rgb.r,
		rt->prs->cylinder->rgb.g, rt->prs->cylinder->rgb.b);
		rt->prs->cylinder = rt->prs->cylinder->next;
	}
	while (rt->prs->cone)
	{
		printf("CONE %d   %f   %f   %f   %f   %f   %f   %f   %f   %i   %i   %i\n", rt->prs->cone->type,
		rt->prs->cone->r.x, rt->prs->cone->r.y, rt->prs->cone->r.z,
		rt->prs->cone->n.x, rt->prs->cone->n.y, rt->prs->cone->n.z,
		rt->prs->cone->d, rt->prs->cone->h, rt->prs->cone->rgb.r,
		rt->prs->cone->rgb.g, rt->prs->cone->rgb.b);
		rt->prs->cone = rt->prs->cone->next;
	}
	while (rt->prs->light)
	{
		printf("LIGHT %d   %f   %f   %f   %f   %i   %i   %i\n", rt->prs->light->type,
		rt->prs->light->r.x, rt->prs->light->r.y, rt->prs->light->r.z,
		rt->prs->light->brt, rt->prs->light->rgb.r, rt->prs->light->rgb.g, rt->prs->light->rgb.b);
		rt->prs->light = rt->prs->light->next;
	}
	while (rt->prs->plane)
	{
		printf("PLANE %d   %f   %f   %f   %f   %f   %f   %i   %i   %i\n", rt->prs->plane->type,
		rt->prs->plane->r.x, rt->prs->plane->r.y, rt->prs->plane->r.z,
		rt->prs->plane->n.x, rt->prs->plane->n.y, rt->prs->plane->n.z,
		rt->prs->plane->rgb.r, rt->prs->plane->rgb.g, rt->prs->plane->rgb.b);
		rt->prs->plane = rt->prs->plane->next;
	}
	while (rt->prs->sphere)
	{
		printf("SPHERE %d   %f   %f   %f   %f   %d   %d   %d\n", rt->prs->sphere->type, 
		rt->prs->sphere->r.x, rt->prs->sphere->r.y, rt->prs->sphere->r.z,
		rt->prs->sphere->d, rt->prs->sphere->rgb.r, rt->prs->sphere->rgb.g,
		rt->prs->sphere->rgb.b);
		rt->prs->sphere = rt->prs->sphere->next;
	}
}

/*
int32_t	rgb_to_int(t_rgb3 rgb)
{
	return (rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 255);
}
*/

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
			if (rt->prs->screen->a)
				color = rgb_to_int(vec_to_rgb(antialiasing(rt, j * rt->vp.n_x + i)));
			else
				color = rgb_to_int(vec_to_rgb(rt->vp.hit[j * rt->vp.n_x + i].color));
			mlx_put_pixel(rt->image, i, j, color);
		}
	}
}

/*
void	ft_hook_image(void *data)
{
	t_minirt	*rt;

	rt = data;
	//ft_memset(rt->image->pixels, 100, //255, //CHANNELBACK,
	//	rt->image->width * rt->image->height * sizeof(int32_t));
	print_picture(rt);
}

*/

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

//int	main(int32_t argc, char *argv[])
int	make_picture(t_minirt *rt)
{
	ft_printf("Transforming scene\n");
	transform_scene(rt);
/*
	t_dist_cc precalc;
	t_num	t = dist_to_cylin((t_vec3d){0,0,0},(t_vec3d){0,0,1}, (t_cylinder *)rt->prs->cone, &precalc);
	printf("dist to cylinder t=%lf\n", t);
	exit (0);
*/
	ft_printf("Initializing viewport\n");
	init_viewport(rt);
	ft_printf("Setting hit scene\n");
	hit_scene(rt);
	// calc color of object in each pixel for bump and checkboard
	ft_printf("Setting orientation vectors\n");
	make_norm_vec(rt);
	set_checkboard(rt);
	ft_printf("Setting MLX\n");
	rt->mlx = mlx_init(rt->prs->screen->width, rt->prs->screen->height,
			"MLX42", true);
	if (!rt->mlx)
		generic_errors_handler(MLX_ERR_MSG, MLX_ERR, rt);
	rt->image = mlx_new_image(rt->mlx, rt->vp.n_x, rt->vp.n_y);
	if (!rt->image)
		generic_errors_handler(MLX_IMG_ERR_MSG, MLX_IMG_ERR, rt);
	if (mlx_image_to_window(rt->mlx, rt->image, 0, 0) == -1)
		generic_errors_handler(MLX_IMG_W_ERR_MSG, MLX_IMG_W_ERR, rt);
	ft_printf("Rendering image\n");
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
	//print_ll(rt);
	make_picture(rt);
	cleaner(rt);
	return (SUCCESS);
}
