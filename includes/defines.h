/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:24:10 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/02 00:51:08 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

enum	e_characters
{
	NULL_TERM,
	HT = 9,
	NL = 10,
	SPACE = 32,
	PLUS = 43,
	MINUS = 45,
	DOT = 46,
	ZERO = 48,
	FIVE = 53,
};

enum	e_exit_codes
{
	SUCCESS,
	MALLOC_ERR,
	NUM_FILES_ERR,
	FILE_OPEN_ERR = 10,
	FILE_READ_ERR = 20,
	FILE_CLOSE_ERR = 30,
	GNL_ERR = 100,
	NUM_ERR = 200,
	ELEM_ERR = 201,
};

enum	e_num_params
{
	AL_PARAMS = 3,
	C_PARAMS = 4,
	L_PARAMS = 4,
	SP_PARAMS = 4,
	PL_PARAMS = 4,
	CY_PARAMS = 6,
};

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef ARGS_MAX
#  define ARGS_MAX 10
# endif

# ifndef ATOF_MAX
#  define ATOF_MAX 6
# endif

# ifndef ROUND_PRT
#  define ROUND_PRT 0.000001
# endif

# ifndef MALLOC_ERR_MSG
#  define MALLOC_ERR_MSG "Malloc error occured\n"
# endif

# ifndef NUM_FILES_ERR_MSG
#  define NUM_FILES_ERR_MSG "More than one file provided\n"
# endif

# ifndef FILE_OPEN_ERR_MSG
#  define FILE_OPEN_ERR_MSG "Failed to open the file\n"
# endif

# ifndef FILE_READ_ERR_MSG
#  define FILE_READ_ERR_MSG "Failed to read the file\n"
# endif

# ifndef FILE_CLOSE_ERR_MSG
#  define FILE_CLOSE_ERR_MSG "Failed to close the file\n"
# endif

# ifndef GNL_GENERIC_ERR_MSG
#  define GNL_GENERIC_ERR_MSG "Get_next_line inner error\n"
# endif

# ifndef NUMBER_FORMAT_ERR_MSG
#  define NUMBER_FORMAT_ERR_MSG "Wrong number format in .rt config\n"
# endif

# ifndef ELEM_FORMAT_ERR_MSG
#  define ELEM_FORMAT_ERR_MSG "Wrong element format in .rt config\n"
# endif

#endif
