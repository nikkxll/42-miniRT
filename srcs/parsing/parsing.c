/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:22:37 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 20:20:28 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	elem_type_selection(char *entities[ARGS_MAX], t_minirt *rt)
{
	if (ft_strcmp(entities[0], "A") == 0)
		init_a(entities, rt);
	else if (ft_strcmp(entities[0], "C") == 0)
		init_c(entities, rt);
	// else if (ft_strcmp(entities[0], "L") == 0 && !rt->col->light
	// 	&& ft_arrlen((void **)entities) == L_PARAMS)
	// 	init_l(entities, rt);
	// else if (ft_strcmp(entities[0], "sp") == 0
	// 	&& ft_arrlen((void **)entities) == SP_PARAMS)
	// 	init_sp(entities, rt);
	// else if (ft_strcmp(entities[0], "pl") == 0
	// 	&& ft_arrlen((void **)entities) == PL_PARAMS)
	// 	init_pl(entities, rt);
	// else if (ft_strcmp(entities[0], "cy") == 0
	// 	&& ft_arrlen((void **)entities) == CY_PARAMS)
	// 	init_cy(entities, rt);
	else
		return ;
}

void	init_element(t_minirt *rt)
{
	char	*entities[ARGS_MAX];

	(void)rt;
	ft_bzero((void *)entities, ARGS_MAX * sizeof(char *));
	process_args_w_sp_ht(rt->line, entities, 0);
	elem_type_selection(entities, rt);
}

void	parser(char **av, t_minirt *rt)
{
	int		fd;
	char	*buffer;
	int		gnl_status;

	rt->line = "";
	buffer = NULL;
	gnl_status = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		generic_errors_handler(FILE_OPEN_ERR_MSG, FILE_OPEN_ERR, rt);
	while (rt->line != NULL)
	{
		rt->line = get_next_line(fd, &gnl_status, &buffer);
		if (rt->line == NULL && gnl_status != 0)
			gnl_errors_handler(gnl_status);
		else if (rt->line == NULL && gnl_status == 0)
			break ;
		init_element(rt);
		free(rt->line);
	}
}
