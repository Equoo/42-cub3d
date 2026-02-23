/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 06:31:54 by zsonie            #+#    #+#             */
/*   Updated: 2026/02/23 11:30:27 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "types/rgba.h"

int	secure_open(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		ft_printf(ERR_OPEN_FAIL, path);
		return (1);
	}
	return (0);
}

int	dir_to_int(char c)
{
	if (c == 'N')
		return (270);
	else if (c == 'E')
		return (0);
	else if (c == 'S')
		return (90);
	else if (c == 'W')
		return (180);
	else
		return (-1);
}

int	valid_properties(int valid[])
{
	int	i;

	i = 0;
	while (i < 6 && valid[i] == 1)
		i++;
	return (i == 6);
}

int	valid_rgb_format(char *str)
{
	int	commas;
	int	i;

	if (!str || str[0] == ',')
		return (0);
	commas = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ',')
		{
			if (str[i + 1] == ',' || str[i + 1] == '\0' || str[i + 1] == '\n')
				return (0);
			commas++;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (commas == 2);
}
