/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/06 14:21:49 by apimikov         ###   ########.fr       */
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


int32_t	rgb_to_int(t_rgb3 rgb)
{
	return (rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 255);
}


void	print_picture(t_minirt *rt)
{
	int	i;
	int	j;
	int32_t color;
	//t_num t;
	t_sphere *sphere;

	sphere = rt->prs->sphere;
	color = rgb_to_int(sphere->rgb);
	j = -1;
	while (++j < rt->vp.n_y)
	{
		i = -1;
		while (++i < rt->vp.n_x)
		{
			color = rgb_to_int(rt->vp.hit[j * rt->vp.n_x + i].rgb);
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



//int	main(int32_t argc, char *argv[])
int	make_picture(t_minirt *rt)
{
 //   t_minirt rt;


	// creating viewport
	t_num foc = rt->prs->camera->fov;
	int	n_x = rt->prs->screen->width;
	int n_y = rt->prs->screen->height;
	//printf("")
	
	rt->vp = (t_viewport){foc, n_x, n_y, n_x * n_y, NULL, NULL};
	
	/*
	// creating 3nd sphere 
	t_vec3d r = {4, 2, 5};
	t_rgb3	col = {10, 10, 200};
	t_sphere sphere3 = (t_sphere){0, r, 1, col, NULL};

	// creating 2nd sphere 
	r = (t_vec3d){0, 1, 5};
	col = (t_rgb3){10, 200, 10};
	t_sphere sphere2 = (t_sphere){0, r, 1, col, &sphere3};
	
	// creating sphere 
	r = (t_vec3d){0, 0, 5};
	col = (t_rgb3){200, 10, 10};
	rt.sphere = (t_sphere){0, r, 2, col, &sphere2};
	
	// putting sphere into parsing
	t_parse		prs;
	prs.sphere = &(rt.sphere);
	prs.cylinder = NULL;
	prs.plane = NULL;
	rt.prs = &prs;

	//putting camera into parsing
	t_camera cam;
	cam.r = (t_vec3d){0, 0, 0};
	cam.n = (t_vec3d){0, 0, 1};
	cam.n = vec_unit(cam.n);
	prs.camera = &cam;
	*/

	transform_scene(rt);
	init_viewport(&(rt->vp));
	hit_scene(rt);

	rt->mlx = mlx_init(rt->prs->screen->width, rt->prs->screen->height,
		"MLX42", true);
	if (!rt->mlx)
        return (1); //	ft_mlx_error(fdf, 0);
	rt->image = mlx_new_image(rt->mlx, n_x, n_y);
	if (!rt->image)
	    return (1); 	//	ft_mlx_error(fdf, 1);
	if (mlx_image_to_window(rt->mlx, rt->image, 0, 0) == -1)
		return (1); 	//ft_mlx_error(fdf, 1);
	mlx_loop_hook(rt->mlx, ft_hook_image, rt);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_loop(rt->mlx);
	mlx_terminate(rt->mlx);
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
	// print_ll(rt);
	cleaner(rt);
	return (SUCCESS);
}
