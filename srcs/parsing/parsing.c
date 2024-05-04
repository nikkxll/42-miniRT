/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:22:37 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/04 14:31:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	postprocessing(t_minirt *rt)
{
	if (!rt->prs->aml)
		generic_errors_handler(AML_ERR_MSG, AML_ERR, rt);
	if (!rt->prs->camera)
		generic_errors_handler(CAMERA_ERR_MSG, CAM_ERR, rt);
}

void	parser(char **av, t_minirt *rt)
{
	char	*buffer;
	int		gnl_status;

	rt->prs->line = "";
	buffer = NULL;
	gnl_status = 0;
	rt->prs->fd = open(av[1], O_RDONLY);
	if (rt->prs->fd < 0)
		generic_errors_handler(FILE_OPEN_ERR_MSG, FILE_OPEN_ERR, rt);
	while (rt->prs->line != NULL)
	{
		rt->prs->line = get_next_line(rt->prs->fd, &gnl_status, &buffer);
		if (rt->prs->line == NULL && gnl_status != 0)
			gnl_errors_handler(gnl_status);
		else if (rt->prs->line == NULL && gnl_status == 0)
			break ;
		init_element(rt);
		free(rt->prs->line);
	}
	close(rt->prs->fd);
	postprocessing(rt);
}
