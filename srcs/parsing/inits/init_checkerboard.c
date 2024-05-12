/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checkerboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:34:13 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 15:07:32 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

void	init_cone_checker(t_cone *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	char	*rgb_ch[ARGS_MAX];

	if (entities[6])
	{
		if (ft_strcmp(entities[6], "checker") == 0)
		{
			node->opt = CHECKER;
			ft_bzero((void *)rgb_ch, ARGS_MAX * sizeof(char *));
			if (process_args_w_commas(entities[7], rgb_ch, 0) == false)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			if (ft_arrlen((void **)rgb_ch) != VEC_LEN)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			node->rgb_ch.r = protected_atoi(rgb_ch[0], rt);
			node->rgb_ch.g = protected_atoi(rgb_ch[1], rt);
			node->rgb_ch.b = protected_atoi(rgb_ch[2], rt);
			rgb_check(node->rgb_ch.r, node->rgb_ch.g, node->rgb_ch.b, rt);
			node->quan_ch = protected_atoi(entities[8], rt);
			if (node->quan_ch < 1 || node->quan_ch > MAX_CHECKER_QUAN)
				generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
	else
		node->opt = NO_OPTIONS;
}

void	init_cylinder_checker(t_cylinder *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	char	*rgb_ch[ARGS_MAX];

	if (entities[6])
	{
		if (ft_strcmp(entities[6], "checker") == 0)
		{
			node->opt = CHECKER;
			ft_bzero((void *)rgb_ch, ARGS_MAX * sizeof(char *));
			if (process_args_w_commas(entities[7], rgb_ch, 0) == false)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			if (ft_arrlen((void **)rgb_ch) != VEC_LEN)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			node->rgb_ch.r = protected_atoi(rgb_ch[0], rt);
			node->rgb_ch.g = protected_atoi(rgb_ch[1], rt);
			node->rgb_ch.b = protected_atoi(rgb_ch[2], rt);
			rgb_check(node->rgb_ch.r, node->rgb_ch.g, node->rgb_ch.b, rt);
			node->quan_ch = protected_atoi(entities[8], rt);
			if (node->quan_ch < 1 || node->quan_ch > MAX_CHECKER_QUAN)
				generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
	else
		node->opt = NO_OPTIONS;
}

void	init_plane_checker(t_plane *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	char	*rgb_ch[ARGS_MAX];

	if (entities[4])
	{
		if (ft_strcmp(entities[4], "checker") == 0)
		{
			node->opt = CHECKER;
			ft_bzero((void *)rgb_ch, ARGS_MAX * sizeof(char *));
			if (process_args_w_commas(entities[5], rgb_ch, 0) == false)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			if (ft_arrlen((void **)rgb_ch) != VEC_LEN)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			node->rgb_ch.r = protected_atoi(rgb_ch[0], rt);
			node->rgb_ch.g = protected_atoi(rgb_ch[1], rt);
			node->rgb_ch.b = protected_atoi(rgb_ch[2], rt);
			rgb_check(node->rgb_ch.r, node->rgb_ch.g, node->rgb_ch.b, rt);
			node->size_ch = custom_atof(entities[6], 0, 0, rt);
			if (node->size_ch < ROUND_PRT || node->size_ch > ELEM_SIZE_MAX)
				generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
	else
		node->opt = NO_OPTIONS;
}

void	init_sphere_checker(t_sphere *node, t_minirt *rt,
	char *entities[ARGS_MAX])
{
	char	*rgb_ch[ARGS_MAX];

	if (entities[4])
	{
		if (ft_strcmp(entities[4], "checker") == 0)
		{
			node->opt = CHECKER;
			ft_bzero((void *)rgb_ch, ARGS_MAX * sizeof(char *));
			if (process_args_w_commas(entities[5], rgb_ch, 0) == false)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			if (ft_arrlen((void **)rgb_ch) != VEC_LEN)
				generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
			node->rgb_ch.r = protected_atoi(rgb_ch[0], rt);
			node->rgb_ch.g = protected_atoi(rgb_ch[1], rt);
			node->rgb_ch.b = protected_atoi(rgb_ch[2], rt);
			rgb_check(node->rgb_ch.r, node->rgb_ch.g, node->rgb_ch.b, rt);
			node->quan_ch = protected_atoi(entities[6], rt);
			if (node->quan_ch < 1 || node->quan_ch > MAX_CHECKER_QUAN)
				generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
		}
		else
			generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
	}
	else
		node->opt = NO_OPTIONS;
}
