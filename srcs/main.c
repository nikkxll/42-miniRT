/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 22:17:56 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

// void print_ll(t_minirt *rt)
// {
// 	while (rt->prs->aml)
// 	{
// 		printf("AML %d   %f   %d   %d   %d\n", rt->prs->aml->type,
// 			rt->prs->aml->ratio, rt->prs->aml->rgb.r, rt->prs->aml->rgb.g,
// 			rt->prs->aml->rgb.b);
// 		rt->prs->aml = rt->prs->aml->next;
// 	}
// 	while (rt->prs->camera)
// 	{
// 		printf("CAMERA %d   %f   %f   %f   %f   %f   %f   %f\n", rt->prs->camera->type,
// 			rt->prs->camera->r.x, rt->prs->camera->r.y, rt->prs->camera->r.z,
// 			rt->prs->camera->n.x, rt->prs->camera->n.y, rt->prs->camera->n.z,
// 			rt->prs->camera->fov);
// 		rt->prs->camera = rt->prs->camera->next;
// 	}
	// while (rt->prs->cylinder)
	// {
	// 	printf("%d   %f   %d   %d   %d", rt->prs->aml->type,
	// 	rt->prs->aml->ratio, rt->prs->aml->rgb.r, rt->prs->aml->rgb.g,
	// 	rt->prs->aml->rgb.b);
	// 	rt->prs->aml = rt->prs->aml->next;
	// }
	// while (rt->prs->light)
	// {
	// 	printf("%d   %f   %d   %d   %d", rt->prs->aml->type,
	// 	rt->prs->aml->ratio, rt->prs->aml->rgb.r, rt->prs->aml->rgb.g,
	// 	rt->prs->aml->rgb.b);
	// 	rt->prs->aml = rt->prs->aml->next;
	// }
	// while (rt->prs->plane)
	// {
	// 	printf("%d   %f   %d   %d   %d", rt->prs->aml->type,
	// 	rt->prs->aml->ratio, rt->prs->aml->rgb.r, rt->prs->aml->rgb.g,
	// 	rt->prs->aml->rgb.b);
	// 	rt->prs->aml = rt->prs->aml->next;
	// }
	// while (rt->prs->sphere)
	// {
	// 	printf("%d   %f   %d   %d   %d", rt->prs->aml->type,
	// 	rt->prs->aml->ratio, rt->prs->aml->rgb.r, rt->prs->aml->rgb.g,
	// 	rt->prs->aml->rgb.b);
	// 	rt->prs->aml = rt->prs->aml->next;
	// }
// }

int	main(int ac, char **av)
{
	t_minirt	*rt;

	rt = NULL;
	if (ac != 2)
		generic_errors_handler(NUM_FILES_ERR_MSG, NUM_FILES_ERR, rt);
	rt = ft_calloc(1, sizeof(t_minirt));
	if (!rt)
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	rt->prs = ft_calloc(1, sizeof(t_parse));
	if (!rt)
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	parser(av, rt);
	// print_ll(rt);
	cleaner(rt);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		generic_errors_handler(NUM_FILES_ERR_MSG, NUM_FILES_ERR);
// 	printf("%f\n", custom_atof(av[1]));
// 	return (0);
// }