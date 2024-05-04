/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:14:22 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/05 01:08:57 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_bool	zero_check(char *str)
{
	while ((*str >= HT && *str <= CR) || *str == SPACE)
		str++;
	if (*str == PLUS || *str == MINUS)
		str++;
	while (*str == ZERO)
		str++;
	while ((*str >= HT && *str <= CR) || *str == SPACE)
		str++;
	if (*str != NULL_TERM)
		return (true);
	return (false);
}

static t_bool	number_check(char *str)
{
	while ((*str >= HT && *str <= CR) || *str == SPACE)
		str++;
	if (*str == PLUS || *str == MINUS)
		str++;
	while (ft_isdigit(*str))
		str++;
	while ((*str >= HT && *str <= CR) || *str == SPACE)
		str++;
	if (*str != NULL_TERM)
		return (true);
	return (false);
}

int	protected_atoi(char *str, t_minirt *rt)
{
	int	number;

	if (number_check(str))
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	number = ft_atoi(str);
	if (zero_check(str) && number == 0)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	return (number);
}
