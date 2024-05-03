/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:23:27 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/03 13:34:27 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	generic_errors_handler(char *msg, int status, t_minirt *rt)
{
	cleaner(rt);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(status);
}

void	gnl_errors_handler(int status)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (status == -1)
	{
		ft_putstr_fd(FILE_OPEN_ERR_MSG, STDERR_FILENO);
	}
	if (status == 1)
	{
		ft_putstr_fd(MALLOC_ERR_MSG, STDERR_FILENO);
	}
	if (status == 2)
	{
		ft_putstr_fd(FILE_READ_ERR_MSG, STDERR_FILENO);
	}
	if (status == 3)
	{
		ft_putstr_fd(GNL_GENERIC_ERR_MSG, STDERR_FILENO);
	}
	exit(GNL_ERR);
}
