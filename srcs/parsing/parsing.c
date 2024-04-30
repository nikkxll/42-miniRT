/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:22:37 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/30 14:24:22 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	init(char **row, t_minirt *rt)
{
	if (ft_strcmp("A", *row) == 0 && ft_arrlen((void **)row) == 3
		&& !rt->col->aml)
	{
		init_ambient_lightning(row, rt);
	}
	else
		return ;
}

void	parser(char **av, t_minirt *rt)
{
	char	*line;
	int		fd;
	char	*buffer;
	char	**row;
	int		gnl_status;

	buffer = NULL;
	line = "";
	gnl_status = 0;
	while (line != NULL)
	{
		line = get_next_line(fd, &gnl_status, &buffer);
		if (line == NULL && gnl_status != 0)
			gnl_errors_handler(gnl_status);
		else if (line == NULL && gnl_status == 0)
			break ;
		row = ft_splitset(line, " \t");
		free(line);
		if (!row)
			generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR);
		init(row, rt);
		free(row);
	}
}
