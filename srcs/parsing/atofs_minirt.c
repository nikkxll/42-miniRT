/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atofs_minirt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:06:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/30 14:21:23 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_bool	precheck(char *str)
{
	int	check;

	check = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= 48 && *str <= 57)
		str++;
	if (*str == '.')
		str++;
	while (*str >= 48 && *str <= 57)
		str++;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str != '\0')
		return (true);
	return (false);
}

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;

	if (precheck(str))
		return (ATOF_ERROR);
	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		res += res2;
	else
		res -= res2;
}
