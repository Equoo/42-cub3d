/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:58:57 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 03:10:17 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <errno.h>
#include <ft_printf.h>
#include <string.h>

static char	*str_custom_errors(int err)
{
	if (err == ERRMAPRECT)
		return ("Map is not a rectangle");
	if (err == ERRMAPCHAR)
		return ("Invalid characters");
	if (err == ERRMAPPLAYER)
		return ("Double player");
	if (err == ERRMAPEXIT)
		return ("Double exit");
	if (err == ERRMAPWALL)
		return ("Not closed by walls");
	if (err == ERRMAPPATH)
		return ("No path availabe");
	if (err == ERRMAPNOPE)
		return ("No player or exit");
	if (err == ERRTEXARGS)
		return ("Invalid slices or frames arguments");
	if (err == ERRTEXNOFS)
		return ("No frames or slices found");
	if (err == EINVALTEX)
		return ("Invalid texture");
	if (err == ERRMAPSIZE)
		return ("Map is too big");
	return ("Unknown error");
}

/*
** Print a custom error message
** @param category: the category of the error
** @param error: the error message
** @return 1
*/
int	print_cerror(char *category, int error)
{
	static int	err = 0;
	char		*errorstr;

	if (err)
		return (error);
	errno = error;
	err = 1;
	if (error > 133)
		errorstr = str_custom_errors(error);
	else
		errorstr = strerror(error);
	ft_printf("Error\n%s: %s\n", category, errorstr);
	return (error);
}

/*
** Print an error message
** @param category: the category of the error
** @return errno
*/
int	print_error(char *category)
{
	print_cerror(category, errno);
	return (errno);
}
