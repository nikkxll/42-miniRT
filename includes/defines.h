/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:24:10 by dnikifor          #+#    #+#             */
/*   Updated: 2024/04/30 14:13:50 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

enum	e_exit_codes
{
	SUCCESS,
	MALLOC_ERR,
	NUM_FILES_ERR,
	FILE_OPEN_ERR = 10,
	FILE_READ_ERR = 20,
	FILE_CLOSE_ERR = 30,
	GNL_ERR = 100,
};

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef ATOF_ERROR
#  define ATOF_ERROR 1000000
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

#endif
