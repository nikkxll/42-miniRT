/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:23:27 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/05 12:25:28 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	show_number_ranges(void)
{
	ft_putstr_fd(CONFIG_MSG_1, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_2, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_3, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_4, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_5, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_6, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_7, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_8, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_9, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_10, STDERR_FILENO);
}

static void	show_valid_config(void)
{
	ft_putstr_fd(CONFIG_MSG_11, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_12, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_13, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_14, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_13, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_15, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_16, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_17, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_18, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_19, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_20, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_21, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_20, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_22, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_23, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_24, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_25, STDERR_FILENO);
	ft_putstr_fd(CONFIG_MSG_26, STDERR_FILENO);
}

void	generic_errors_handler(char *msg, int status, t_minirt *rt)
{
	cleaner(rt);
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(EC, STDERR_FILENO);
	if (status == NUM_ERR || status == CONF_ERR
		|| status == AML_ERR || status == CAM_ERR)
	{
		show_valid_config();
		show_number_ranges();
	}
	exit(status);
}

void	gnl_errors_handler(int status, t_minirt *rt)
{
	cleaner(rt);
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	if (status == GNL_FILE_OPEN_ERR)
	{
		ft_putstr_fd(FILE_OPEN_ERR_MSG, STDERR_FILENO);
	}
	if (status == GNL_MALLOC_ERR)
	{
		ft_putstr_fd(MALLOC_ERR_MSG, STDERR_FILENO);
	}
	if (status == GNL_FILE_READ_ERR)
	{
		ft_putstr_fd(FILE_READ_ERR_MSG, STDERR_FILENO);
	}
	if (status == GNL_GENERIC_ERR)
	{
		ft_putstr_fd(GNL_GENERIC_ERR_MSG, STDERR_FILENO);
	}
	ft_putstr_fd(EC, STDERR_FILENO);
	exit(GNL_ERR);
}
