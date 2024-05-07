/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:22:37 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/07 10:36:28 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	preprocessing(t_minirt *rt)
{
	if (VP_SIZE_MAX < 100 || VP_SIZE_MAX > 2000)
		generic_errors_handler(DEF_ERR_MSG, DEF_ERR, rt);
	if (VP_WIDTH_DEFAULT < 1 || VP_WIDTH_DEFAULT > 9999)
		generic_errors_handler(DEF_ERR_MSG, DEF_ERR, rt);
	if (VP_HEIGHT_DEFAULT < 1 || VP_HEIGHT_DEFAULT > 9999)
		generic_errors_handler(DEF_ERR_MSG, DEF_ERR, rt);
	if (ELEM_SIZE_MAX < 0 || ELEM_SIZE_MAX > 999999.999999
		|| COORD_MAX < -999999.999999 || COORD_MAX > 999999.999999
		|| COORD_MIN < -999999.999999 || COORD_MIN > 999999.999999
		|| COORD_MIN > COORD_MAX)
		generic_errors_handler(DEF_ERR_MSG, DEF_ERR, rt);
	if (ARGS_MAX != 10 || ATOF_MAX != 6 || VEC_LEN != 3)
		generic_errors_handler(DEF_ERR_MSG, DEF_ERR, rt);
	if (BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		generic_errors_handler(DEF_ERR_MSG, DEF_ERR, rt);
}

static void	postprocessing(t_minirt *rt)
{
	t_screen	*node;

	if (!rt->prs->aml)
		generic_errors_handler(AML_ERR_MSG, AML_ERR, rt);
	if (!rt->prs->camera)
		generic_errors_handler(CAMERA_ERR_MSG, CAM_ERR, rt);
	if (!rt->prs->screen)
	{
		node = (t_screen *)ft_calloc(1, sizeof(t_screen));
		if (node)
		{
			node->type = VIEWPORT;
			node->width = VP_WIDTH_DEFAULT;
			node->height = VP_HEIGHT_DEFAULT;
			rt->prs->screen = node;
			ft_printf(ORANGE);
			ft_printf(LOG_MSG_3);
			ft_printf(EC);
		}
		else
			generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	}
}

void	parser(char **av, t_minirt *rt)
{
	char	*buffer;
	int		gnl_status;

	ft_printf(LOG_MSG_1, av[1]);
	preprocessing(rt);
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
			gnl_errors_handler(gnl_status, rt);
		else if (rt->prs->line == NULL && gnl_status == 0)
			break ;
		init_element(rt);
		free(rt->prs->line);
	}
	close(rt->prs->fd);
	postprocessing(rt);
	ft_printf(LOG_MSG_2);
}
