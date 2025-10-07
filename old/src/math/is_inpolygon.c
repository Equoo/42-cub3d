/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inpolygon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:21:45 by dderny            #+#    #+#             */
/*   Updated: 2025/10/03 20:24:04 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2d.h"

static int is_left(t_vec2 *a, t_vec2 *b)
{
    return (-a->x * b->y + a->y * b->x < 0);
}

int  is_inpolygon(t_vec2 *points, int npoints, t_vec2 point)
{
    int     i;
    int     next;
    int     isleft;
    t_vec2  va;
    t_vec2  vb;

    isleft = 1;
    i = 0;
    while (i < npoints)
    {
        next = (i + 1) % npoints;
        va = vec2_sub(points[i], points[next]);
        vb = vec2_sub(point, points[next]);
        if (!is_left(&vb, &va)) {
            isleft = 0;
            break ;
        }
        i++;
    }
    return (isleft);
}

