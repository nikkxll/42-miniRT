/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:24:46 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/04 14:08:51 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_bool	format_check(char *str, int count, int *sign_flag)
{
	if (*str == MINUS || *str == PLUS)
	{
		*sign_flag = *str;
		str++;
	}
	while (ft_isdigit(*str))
	{
		count++;
		str++;
	}
	if ((*str == NULL_TERM || *str == DOT)
		&& count > ATOF_MAX)
		return (false);
	else if (*str != NULL_TERM && *str != DOT)
		return (false);
	if (*str == DOT)
	{
		str++;
		count = 0;
		while (ft_isdigit(*str))
			str++;
	}
	if (*str != NULL_TERM)
		return (false);
	return (true);
}

static double	ft_round(char *c, int len)
{
	size_t	i;
	
	i = 0;
	if (len > ATOF_MAX)
	{
		if (c[ATOF_MAX] == FIVE)
		{
			i++;
			while (c[ATOF_MAX + i] != NULL_TERM
				&& c[ATOF_MAX + i] == ZERO)
				i++;
			if (c[ATOF_MAX + i] == NULL_TERM)
				return (0);
			else
				return (ROUND_PRT);
		}
		else if (c[ATOF_MAX] > FIVE)
			return (ROUND_PRT);
		else
			return (0);
	}
	return (0);
}

double	custom_atof(char *c, double int_prt, double dec_prt, t_minirt *rt)
{
	int		len;
	int		sign_flag;

	sign_flag = 0;
	if (format_check(c, 0, &sign_flag) == false)
		generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR, rt);
	int_prt = (double)ft_atoi(c);
	while (*c && *c != DOT)
		c++;
	if (*c == DOT)
		c++;
	len = ft_strlen(c);
	if (int_prt >= 0 && (sign_flag == PLUS || sign_flag == 0))
		int_prt += ft_round(c, len);
	else
		int_prt -= ft_round(c, len);
	if (len > ATOF_MAX)
		*(c + ATOF_MAX) = NULL_TERM;
	len = ft_strlen(c);
	dec_prt = (double)ft_atoi(c);
	while (len--)
		dec_prt /= 10;
	if (int_prt >= 0 && (sign_flag == PLUS || sign_flag == 0))
		return (int_prt + dec_prt);
	return (int_prt - dec_prt);
}
