/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:06:55 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 22:16:30 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	*next(void **lst, int type)
{
	if (type == AM_LIGHT)
		return ((void *)(((t_am_light *)*lst)->next));
	else if (type == CAMERA)
		return ((void *)(((t_camera *)*lst)->next));
	else if (type == LIGHT)
		return ((void *)(((t_light *)*lst)->next));
	else if (type == SPHERE)
		return ((void *)(((t_sphere *)*lst)->next));
	else if (type == PLANE)
		return ((void *)(((t_plane *)*lst)->next));
	else
		return ((void *)(((t_cylinder *)*lst)->next));
}

static void	ft_lst_remove(void **lst, int type)
{
	void	*current;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		current = *lst;
		*lst = next(lst, type);
		if (type == AM_LIGHT)
			free((t_am_light *)current);
		else if (type == CAMERA)
			free((t_camera *)current);
		else if (type == LIGHT)
			free((t_light *)current);
		else if (type == SPHERE)
			free((t_sphere *)current);
		else if (type == PLANE)
			free((t_plane *)current);
		else
			free((t_cylinder *)current);
	}
}

void	cleaner(t_minirt *rt)
{
	if (rt->line)
		free(rt->line);
	if (rt->prs)
	{
		if (rt->prs->aml)
			ft_lst_remove((void **)&(rt->prs->aml), AM_LIGHT);
		if (rt->prs->camera)
			ft_lst_remove((void **)&rt->prs->camera, CAMERA);
		if (rt->prs->light)
			ft_lst_remove((void **)&rt->prs->light, LIGHT);
		if (rt->prs->sphere)
			ft_lst_remove((void **)&rt->prs->sphere, SPHERE);
		if (rt->prs->plane)
			ft_lst_remove((void **)&rt->prs->plane, PLANE);
		if (rt->prs->cylinder)
			ft_lst_remove((void **)&rt->prs->cylinder, CYLINDER);
		free(rt->prs);
	}
	if (rt)
		free(rt);
}
