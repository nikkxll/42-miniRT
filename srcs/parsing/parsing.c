/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:22:37 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/01 12:57:44 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// void	elem_type_selection(char *entities[ARGS_MAX], t_minirt *rt)
// {
// 	if (ft_strcmp(entities[0], "A") == 0 && !rt->col->aml
// 		&& ft_arrlen((void **)entities) == AL_PARAMS)
// 		init_al();
// 	else if (ft_strcmp(entities[0], "C") == 0 && !rt->col->camera
// 		&& ft_arrlen((void **)entities) == C_PARAMS)
// 		init_al();
// 	else if (ft_strcmp(entities[0], "L") == 0 && !rt->col->light
// 		&& ft_arrlen((void **)entities) == L_PARAMS)
// 		init_al();
// 	else if (ft_strcmp(entities[0], "sp") == 0
// 		&& ft_arrlen((void **)entities) == SP_PARAMS)
// 		init_al();
// 	else if (ft_strcmp(entities[0], "pl") == 0
// 		&& ft_arrlen((void **)entities) == PL_PARAMS)
// 		init_al();
// 	else if (ft_strcmp(entities[0], "cy") == 0
// 		&& ft_arrlen((void **)entities) == CY_PARAMS)
// 		init_al();
// 	else
// 		generic_errors_handler(ELEM_FORMAT_ERR_MSG, ELEM_ERR);
// }

void	process_args(char *line, char *entities[ARGS_MAX], int count)
{
    while (*line != NULL_TERM && count < ARGS_MAX)
	{
		while (*line == SPACE || *line == HT)
			line++;
        if (*line == NULL_TERM)
			break ;
		entities[count++] = line;
		while (*line != SPACE && *line != HT
				&& *line != NULL_TERM && *line != NL)
			line++;
        if (*line != NULL_TERM || *line == NL)
		{
			*line = NULL_TERM;
			line++;
		}
	}
}

void	init_element(char *line, t_minirt *rt)
{
	char	*entities[ARGS_MAX];
	
	(void)rt;
	ft_bzero((void *)entities, ARGS_MAX * sizeof(char *));
	process_args(line, entities, 0);
	// elem_type_selection(entities, rt);
}

void	parser(char **av, t_minirt *rt)
{
	char	*line;
	int		fd;
	char	*buffer;
	int		gnl_status;

	line = "";
	buffer = NULL;
	gnl_status = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		generic_errors_handler(FILE_OPEN_ERR_MSG, FILE_OPEN_ERR);
	while (line != NULL)
	{
		line = get_next_line(fd, &gnl_status, &buffer);
		if (line == NULL && gnl_status != 0)
			gnl_errors_handler(gnl_status);
		else if (line == NULL && gnl_status == 0)
			break ;
		init_element(line, rt);
		free(line);
	}
}
