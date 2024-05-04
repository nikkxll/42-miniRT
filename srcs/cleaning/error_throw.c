/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:23:27 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/04 14:15:49 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	show_config_template()
{
	ft_putstr_fd("\nExample of the correct .rt file format:\n", STDERR_FILENO);
	ft_putstr_fd("A     ratio    r,g,b\n", STDERR_FILENO);
	ft_putstr_fd("C     x,y,z    x_n,y_n,x_n  FOV\n", STDERR_FILENO);
	ft_putstr_fd("L     x,y,z    ratio        r,g,b\n", STDERR_FILENO);
	ft_putstr_fd("sp    x,y,z    diameter     r,g,b\n", STDERR_FILENO);
	ft_putstr_fd("pl    x,y,z    x_n,y_n,x_n  r,g,b\n", STDERR_FILENO);
	ft_putstr_fd("cy    x,y,z    x_n,y_n,x_n  diameter  height  r,g,b\n",
		STDERR_FILENO);
}

void	generic_errors_handler(char *msg, int status, t_minirt *rt)
{
	cleaner(rt);
	ft_putstr_fd("\x1B[31m", STDERR_FILENO);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\x1B[0m", STDERR_FILENO);
	if (status == NUM_ERR || status == CONF_ERR
		|| status == AML_ERR || status == CAM_ERR)
		show_config_template();
	exit(status);
}

void	gnl_errors_handler(int status)
{
	ft_putstr_fd("\x1B[31m", STDERR_FILENO);
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
	ft_putstr_fd("\x1B[0m", STDERR_FILENO);
	exit(GNL_ERR);
}
