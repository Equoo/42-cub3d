/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:37 by dderny            #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

# define TIME_PARSE "se.exec_start"

/**
** @brief Get the current time in seconds
**
** @return time in seconds since the start of the program
*/
double	ft_uptime(void);


double  curtime_us(void);

#endif
