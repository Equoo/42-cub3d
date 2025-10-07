/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:37 by dderny            #+#    #+#             */
/*   Updated: 2025/04/26 03:09:56 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define EMLXINIT "MLX initialization"

# define MAPERR_CATEGORY "Loading map"
# define MAPERROR 1000
# define ERRMAPRECT 1001
# define ERRMAPCHAR 1002
# define ERRMAPPLAYER 1003
# define ERRMAPEXIT 1004
# define ERRMAPWALL 1005
# define ERRMAPCOIN 1006
# define ERRMAPPATH 1006
# define ERRMAPNOPE 1007
# define ERRMAPSIZE 1008

# define TEXTERR_CATEGORY "Loading texture"
# define TEXTERROR 2000
# define ERRTEXARGS 2001
# define ERRTEXNOFS 2002
# define EINVALTEX 2003

int	print_error(char *category);
int	print_cerror(char *category, int error);

#endif
