/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:06:55 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/10 19:27:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	*next(void **lst, int type)
{
	if (type == LIGHT)
		return ((void *)(((t_light *)*lst)->next));
	else if (type == SPHERE)
		return ((void *)(((t_sphere *)*lst)->next));
	else if (type == PLANE)
		return ((void *)(((t_plane *)*lst)->next));
	else if (type == CYLINDER)
		return ((void *)(((t_cylinder *)*lst)->next));
	else if (type == CONE)
		return ((void *)(((t_cone *)*lst)->next));
	else
		return (NULL);
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
		if (type == LIGHT)
			free((t_light *)current);
		else if (type == SPHERE)
			free((t_sphere *)current);
		else if (type == PLANE)
			free((t_plane *)current);
		else if (type == CYLINDER)
			free((t_cylinder *)current);
		else if (type == CONE)
			free((t_cone *)current);
	}
}

void	clean_elements(t_minirt *rt)
{
	if (rt->prs->screen)
		free(rt->prs->screen);
	if (rt->prs->aml)
		free(rt->prs->aml);
	if (rt->prs->camera)
		free(rt->prs->camera);
	if (rt->prs->light)
		ft_lst_remove((void **)&rt->prs->light, LIGHT);
	if (rt->prs->sphere)
		ft_lst_remove((void **)&rt->prs->sphere, SPHERE);
	if (rt->prs->plane)
		ft_lst_remove((void **)&rt->prs->plane, PLANE);
	if (rt->prs->cylinder)
		ft_lst_remove((void **)&rt->prs->cylinder, CYLINDER);
	if (rt->prs->cone)
		ft_lst_remove((void **)&rt->prs->cone, CONE);
}

void	cleaner(t_minirt *rt)
{
	if (rt && rt->prs && rt->prs->fd > -1)
		close(rt->prs->fd);
	if (rt && rt->prs && rt->prs->line && *rt->prs->line)
		free(rt->prs->line);
	if (rt && rt->vp.hit)
		free(rt->vp.hit);
	if (rt && rt->prs)
	{
		clean_elements(rt);
		free(rt->prs);
	}
	if (rt && rt->mlx && rt->image)
		mlx_delete_image(rt->mlx, rt->image);
	if (rt && rt->mlx)
		mlx_terminate(rt->mlx);
	if (rt)
		free(rt);
}
