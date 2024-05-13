/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:24:10 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/12 19:35:51 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

enum	e_types
{
	AM_LIGHT = 1,
	CAMERA,
	LIGHT,
	MULTILIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	VIEWPORT,
	TYPE_OBJ_NONE
};

enum	e_characters
{
	NULL_TERM,
	HT = 9,
	NL = 10,
	CR = 13,
	SPACE = 32,
	PLUS = 43,
	COMMA = 44,
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
	CONF_ERR = 201,
	AML_ERR = 202,
	CAM_ERR = 203,
	MLX_ERR = 300,
	MLX_IMG_ERR = 301,
	MLX_IMG_W_ERR = 302,
	DEF_ERR = 999,
};

enum	e_num_params
{
	VP_PARAMS = 3,
	AL_PARAMS = 3,
	C_PARAMS = 4,
	L_PARAMS = 4,
	SP_PARAMS = 4,
	PL_PARAMS = 4,
	CY_PARAMS = 6,
	CO_PARAMS = 6,
};

enum	e_num_params_opt
{
	VP_PARAMS_OPT = 4,
	SP_PARAMS_CH = 7,
	PL_PARAMS_CH = 7,
	CY_PARAMS_CH = 9,
	CO_PARAMS_CH = 9,
};

enum	e_checker
{
	NO_OPTIONS,
	CHECKER,
	BUMP,
};

enum	e_antialiasing
{
	ON,
	OFF,
};

enum	e_gnl_error_codes
{
	GNL_FILE_OPEN_ERR = -1,
	GNL_MALLOC_ERR = 1,
	GNL_FILE_READ_ERR = 2,
	GNL_GENERIC_ERR = 3,
};

enum	e_angles
{
	ALPHA,
	BETA,
};

# define DEBUG_MOD 1

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define ORANGE "\e[38;5;208m"
# define EC "\x1B[0m"

# define ARGS_MAX 15
# define ATOF_MAX 6
# define VEC_LEN 3

# define VP_SIZE_MAX 2000
# define VP_SIZE_MIN 100
# define VP_WIDTH_DEFAULT 1000
# define VP_HEIGHT_DEFAULT 800
# define MAX_CHECKER_QUAN 999
# define MAX_FOV 179
# define MIN_FOV 1
# define ELEM_SIZE_MAX 999999.999999
# define COORD_MAX 999999.999999
# define COORD_MIN -999999.999999
# define ROUND_PRT 0.000001

# define TAN tan
# define POW pow
# define SQRT sqrt

# define PI 3.141592653589793238462
# define EPSILON 0.0000001

// matherial properties
# define COEF_OBJS 0.1
# define COEF_AMBI 1
# define COEF_DIFF 1
# define COEF_SPEC 1
# define COEF_ALPHA 1000
# define COEF_REFLECT 1

# define PRS_LOG_MSG_1 "-- Camera initialized successfully\n"
# define PRS_LOG_MSG_2 "-- Ambient light initialized successfully\n"
# define PRS_LOG_MSG_3 "-- Sphere element initialized successfully\n"
# define PRS_LOG_MSG_4 "-- Plane element initialized successfully\n"
# define PRS_LOG_MSG_5 "-- Cylinder element initialized successfully\n"
# define PRS_LOG_MSG_6 "-- Cone element initialized successfully\n"
# define PRS_LOG_MSG_7 "-- Light element initialized successfully\n"
# define PRS_LOG_MSG_8 "-- Viewport initialized successfully\n"
# define PRS_LOG_MSG_9 "-- Antialiasing disabled\n"
# define PRS_LOG_MSG_10 "-- Antialiasing enabled\n"

# define LOG_MSG_1 "-- Parsing input file '%s'\n"
# define LOG_MSG_2 "-- Parsing finished successfully\n"
# define LOG_MSG_3 "-- Warning! Viewport dimension are taken by default\n"
# define LOG_MSG_4 "-- Transforming scene\n"
# define LOG_MSG_5 "-- Initializing viewport\n"
# define LOG_MSG_6 "-- Setting hit scene\n"
# define LOG_MSG_7 "-- Setting orientation vectors\n"
# define LOG_MSG_8 "-- Setting MLX\n"
# define LOG_MSG_9 "-- Rendering scene\n"

# define ERR_MSG "Error\n"
# define MALLOC_ERR_MSG "Malloc error occured\n"
# define NUM_FILES_ERR_MSG "More than one file or no files provided\n"
# define FILE_OPEN_ERR_MSG "Failed to open the file\n"
# define FILE_READ_ERR_MSG "Failed to read the file\n"
# define FILE_CLOSE_ERR_MSG "Failed to close the file\n"
# define GNL_GENERIC_ERR_MSG "Get_next_line inner error\n"
# define NUMBER_FORMAT_ERR_MSG "Wrong number format in .rt config\n"
# define CONF_FORMAT_ERR_MSG "Wrong config structure format in .rt file\n"
# define AML_ERR_MSG "Ambient light element config not found in .rt file\n"
# define CAMERA_ERR_MSG "Camera element config not found in .rt file\n"
# define DEF_ERR_MSG "Critical changes in DEFINE. Program terminated\n"
# define MLX_ERR_MSG "Failed to initiate MLX entity\n"
# define MLX_IMG_ERR_MSG "Failed to create MLX image\n"
# define MLX_IMG_W_ERR_MSG "Failed to put MLX image to window\n"

# define CONFIG_MSG_1 "Example of the valid number ranges:\n\n"
# define CONFIG_MSG_2 "ratio is in range         (0.0, 1.0)\n"
# define CONFIG_MSG_3 "r,g,b are in range        [0, 255]\n"
# define CONFIG_MSG_4 "x,y,z are in range        (-1000000, 1000000)\n"
# define CONFIG_MSG_5 "x_n,y_n,x_n are in range  [-1, 1]\n"
# define CONFIG_MSG_6 "FOV is in range           (0, 180)\n"
# define CONFIG_MSG_7 "cy diameter is in range   (0, 1000000)\n"
# define CONFIG_MSG_8 "cy height is in range     (0, 1000000)\n"
# define CONFIG_MSG_9 "R width is in range       (100, 2000)\n"
# define CONFIG_MSG_10 "R height is in range      (100, 2000)\n"
# define CONFIG_MSG_11 "\nExample of the valid .rt file format:\n\n"
# define CONFIG_MSG_12 "A   ratio   r,g,b        [antialiasing]\n"
# define CONFIG_MSG_13 "C   x,y,z   x_n,y_n,x_n  FOV\n"
# define CONFIG_MSG_14 "L   x,y,z   ratio        r,g,b (one light)\n"
# define CONFIG_MSG_15 "l   x,y,z   ratio        r,g,b (multiple)\n"
# define CONFIG_MSG_16 "sp  x,y,z   d            r,g,b [checker] [r,g,b] [q]\n"
# define CONFIG_MSG_17 "pl  x,y,z   x_n,y_n,x_n  r,g,b [checker] [r,g,b] [s]\n"
# define CONFIG_MSG_18 "cy  x,y,z   x_n,y_n,x_n  d      h         r,g,b  "
# define CONFIG_MSG_19 "co  x,y,z   x_n,y_n,x_n  d      h         r,g,b  "
# define CONFIG_MSG_20 "[checker] [r,g,b] [q]\n"
# define CONFIG_MSG_21 "q is in range             (0, 1000)\n"
# define CONFIG_MSG_22 "s is in range             (0, 1000000)\n\n"
# define CONFIG_MSG_23 "R   width   height       a\n\n"

#endif
