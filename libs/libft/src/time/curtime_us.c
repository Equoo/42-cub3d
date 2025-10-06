/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curtime_us.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:51:53 by dderny            #+#    #+#             */
/*   Updated: 2025/09/24 19:53:03 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>

double curtime_us(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000);
}

