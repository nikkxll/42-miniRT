/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_arr_creation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:16:00 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 18:16:13 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	process_args_w_commas(char *line, char *entities[ARGS_MAX], int count)
{
	while (*line != NULL_TERM && count < ARGS_MAX)
	{
		while (*line == COMMA)
			line++;
		if (*line == NULL_TERM)
			break ;
		entities[count++] = line;
		while (*line != COMMA && *line != NULL_TERM && *line != NL)
			line++;
		if (*line != NULL_TERM || *line == NL)
		{
			*line = NULL_TERM;
			line++;
		}
	}
}

void	process_args_w_sp_ht(char *line, char *entities[ARGS_MAX], int count)
{
	while (*line != NULL_TERM && count < ARGS_MAX)
	{
		while (*line == SPACE || *line == HT)
			line++;
		if (*line == NULL_TERM)
			break ;
		entities[count++] = line;
		while (*line != SPACE && *line != HT
			&& *line != NULL_TERM && *line != NL)
			line++;
		if (*line != NULL_TERM || *line == NL)
		{
			*line = NULL_TERM;
			line++;
		}
	}
}
