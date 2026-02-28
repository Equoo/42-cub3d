/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 07:37:52 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 23:31:57 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# define ERR_INVALID_CHAR "Error\n\033[1;31mParsing->\033[1;32m\
Invalid char\n\033[0m"
# define ERR_OPEN_FAIL "Error\n\033[1;31mParsing->\033[1;32m\
Open failed on %s\n\033[0m"

# define ERR_XPM_FORMAT "Error\n\033[1;31mParsing->\033[1;32m\
XPM validation failed at index[%d]\n\033[0m"
# define ERR_TEXTURE_PATH "Error\n\033[1;31mParsing->\033[1;32m\
Texture path format issue: %s\n\033[0m"
# define ERR_TEXTURE_OPEN "Error\n\033[1;31mParsing->\033[1;32m\
Cannot open texture at index[%d]: %s\n\033[0m"
# define ERR_TEXTURE_MISS "Error\n\033[1;31mParsing->\033[1;32m\
Missing/Duplicated textures.\n\033[0m"

# define ERR_COLORS_MISS "Error\n\033[1;31mParsing->\033[1;32m\
Missing/Duplicated colors.\n\033[0m"
# define ERR_COLORS_RGB "Error\n\033[1;31mParsing->\033[1;32m\
Wrong rgb. Proceed as follow: \"[C/F] [0-255],[0-255],[0-255]\"\n\033[0m"

# define ERR_MAP_SIZE "Error\n\033[1;31mParsing->\033[1;32m\
Map size exceeds maximum size (%d)\n\033[0m"
# define ERR_MAP_LAST "Error\n\033[1;31mParsing->\033[1;32m\
Map should be last.\n\033[0m"
# define ERR_MAP_MISS "Error\n\033[1;31mParsing->\033[1;32m\
Missing Map\n\033[0m"
# define ERR_MAP_FORMAT "Error\n\033[1;31mParsing->\033[1;32m\
Wrong map format.\n\033[0m"

# define ERR_SURROUNDED_SPACE "Error\n\033[1;31mParsing->\033[1;32m\
Map not properly surrounded - space reached from filled area\n\033[0m"
# define ERR_SURROUNDED_EDGE "Error\n\033[1;31mParsing->\033[1;32m\
Map not properly surrounded - filled area touches edge\n\033[0m"

# define ERR_PLAYER_POS "Error\n\033[1;31mParsing->\033[1;32m\
Invalid player spawn\n\033[0m"
# define ERR_PLAYER_COUNT "Error\n\033[1;31mParsing->\033[1;32m\
Invalid player count\n\033[0m"
# define ERR_UNKNOWN_ID "Error\n\033[1;31mParsing->\033[1;32m\
Unknown identifier\n\033[0m"

#endif
