/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:09:21 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/05 01:21:28 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
#include <stdio.h>
# include <math.h>
# include "structs.h"
# include "defines.h"

/*_____ Cleaning _____*/

void	generic_errors_handler(char *msg, int status, t_minirt *rt);
void	gnl_errors_handler(int status, t_minirt *rt);
void	cleaner(t_minirt *rt);

/*_____ Parsing _____*/

void	parser(char **av, t_minirt *rt);

double	custom_atof(char *c, double int_prt, double dec_prt, t_minirt *rt);
int		protected_atoi(char *str, t_minirt *rt);

void	process_args_w_sp_ht(char *line, char *entities[ARGS_MAX], int count);
t_bool	process_args_w_commas(char *line, char *entities[ARGS_MAX], int count);

void	init_struct(t_minirt **rt);
void	init_element(t_minirt *rt);
void	init_a(char *entities[ARGS_MAX], t_minirt *rt);
void	init_c(char *entities[ARGS_MAX], t_minirt *rt);
void	init_l(char *entities[ARGS_MAX], t_minirt *rt, int spec);
void	init_sp(char *entities[ARGS_MAX], t_minirt *rt);
void	init_pl(char *entities[ARGS_MAX], t_minirt *rt);
void	init_cy(char *entities[ARGS_MAX], t_minirt *rt);

void	rgb_check(int r, int g, int b, t_minirt *rt);
void	coord_check(double x, double y, double z, t_minirt *rt);
void	orient_vec_check(double x, double y, double z, t_minirt *rt);

#endif