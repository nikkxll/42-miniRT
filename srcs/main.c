/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/04 21:13:09 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void print_ll(t_minirt *rt)
{
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

int	main(int ac, char **av)
{
	t_minirt	*rt;

	rt = NULL;
	if (ac != 2)
		generic_errors_handler(NUM_FILES_ERR_MSG, NUM_FILES_ERR, rt);
	init_struct(&rt);
	parser(av, rt);
	print_ll(rt);
	// cleaner(rt);
	return (SUCCESS);
}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("%f\n", custom_atof(av[1], 0, 0, NULL));
// 	return (0);
// }
