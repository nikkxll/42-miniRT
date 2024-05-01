/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:24:46 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 13:48:36 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_bool  format_check(char *str, int count)
{
	if (*str == MINUS || *str == PLUS)
		str++;
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

double  ft_rounded(char *c, int len, size_t i)
{
    if (len > ATOF_MAX)
    {
        if (c[6] == FIVE)
        {
            i++;
            while (c[6 + i] != NULL_TERM
                && c[6 + i] == ZERO)
                i++;
            if (c[6 + i] == NULL_TERM)
                return (0);
            else
                return (ROUND_PRT);
        }
        else if (c[6] > FIVE)
            return (ROUND_PRT);
        else
            return (0);
    }
    return (0);
}

double  custom_atof(char *c)
{
    double	res;
	double	res2;
	int		len;
    
    if (format_check(c, 0) == false)
        generic_errors_handler(NUMBER_FORMAT_ERR_MSG, NUM_ERR);
	res = (double)ft_atoi(c);
	while (*c && *c != DOT)
		c++;
	if (*c == DOT)
		c++;
	len = ft_strlen(c);
	if (res >= 0)
        res += ft_rounded(c, len, 0);
    else
        res -= ft_rounded(c, len, 0);
    if (len > ATOF_MAX)
        *(c + ATOF_MAX) = NULL_TERM;
	len = ft_strlen(c);
	res2 = (double)ft_atoi(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
        return (res + res2);
	return (res - res2);
}
