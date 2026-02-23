/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:37:52 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 09:05:36 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

# define ERR_PARS "Error\n"RED"Parsing->"GREEN
# define ERR_INVALID_CHAR ERR_PARS"Invalid char\n"RESET
# define ERR_OPEN_FAIL ERR_PARS"Open failed on %s\n"RESET

# define ERR_XPM_FORMAT ERR_PARS"XPM validation failed at index[%d]\n"RESET
# define ERR_TEXTURE_PATH ERR_PARS"Texture path format issue: %s\n"RESET
# define ERR_TEXTURE_OPEN ERR_PARS"Cannot open texture at index[%d]: %s\n"RESET
# define ERR_TEXTURE_MISS ERR_PARS"Missing/Duplicated textures.\n"RESET

# define ERR_COLORS_MISS ERR_PARS"Missing/Duplicated colors.\n"RESET
# define ERR_COLORS_RGB ERR_PARS"Wrong rgb. Proceed as follow: \
\"[C/F] [0-255],[0-255],[0-255]\"\n"RESET

# define ERR_MAP_SIZE ERR_PARS"Map size exceeds maximum size (%d)\n"RESET
# define ERR_MAP_LAST ERR_PARS"Map should be last.\n"RESET
# define ERR_MAP_MISS ERR_PARS"Missing Map\n"RESET
# define ERR_MAP_FORMAT ERR_PARS"Wrong map format.\n"RESET

# define ERR_SURROUNDED_SPACE ERR_PARS"Map not properly surrounded\
 - space reached from filled area\n"RESET
# define ERR_SURROUNDED_EDGE ERR_PARS"Map not properly surrounded\
 - filled area touches edge\n"RESET

 # define ERR_PLAYER_POS ERR_PARS"Invalid player spawn\n"RESET
# define ERR_PLAYER_COUNT ERR_PARS"Invalid player count\n"RESET
# define ERR_UNKNOWN_ID ERR_PARS"Unknown identifier\n"RESET
#endif