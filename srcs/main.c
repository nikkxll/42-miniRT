/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:31 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/01 12:59:29 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double  custom_atof(char *str);

// int	main(int ac, char **av)
// {
// 	t_minirt	*rt;

// 	if (ac != 2)
// 		generic_errors_handler(NUM_FILES_ERR_MSG, NUM_FILES_ERR);
// 	rt = ft_calloc(1, sizeof(t_minirt));
// 	if (!rt)
// 		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR);
// 	parser(av, rt);
// 	return (0);
// }

int	main(int ac, char **av)
{
	if (ac != 2)
		generic_errors_handler(NUM_FILES_ERR_MSG, NUM_FILES_ERR);
	printf("%f\n", custom_atof(av[1]));
	return (0);
}