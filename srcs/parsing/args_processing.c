/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:16:00 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 13:27:45 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_bool	process_args_w_commas(char *line, char *entities[ARGS_MAX], int count)
{
	int	comma_count;

	comma_count = 0;
	entities[count++] = line;
	while (*line != NULL_TERM && count < ARGS_MAX - 1)
	{
		line = ft_strchr(line, COMMA);
		if (line == NULL)
			break ;
		comma_count++;
		if (comma_count > 2)
			return (false);
		*line = NULL_TERM;
		line++;
		if (*line == NULL_TERM)
		{
			entities[count++] = NULL;
			break ;
		}
		entities[count++] = line;
	}
	return (true);
}

void	process_args_w_sp_ht(char *line, char *entities[ARGS_MAX], int count)
{
	while (*line != NULL_TERM && count < ARGS_MAX - 1)
	{
		while (*line == SPACE || *line == HT)
			line++;
		if (*line == NULL_TERM || *line == NL)
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
