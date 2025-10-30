/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 04:06:09 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/30 04:51:17 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIST_H
# define DIST_H

# define MAX_DIST 10000

typedef struct
{
	float	distances[MAX_DIST][MAX_DIST];
}			dist_lut;

dist_lut	*create_distance_lut(void);
void		destroy_distance_lut(dist_lut *lut);
float		get_distance_lut(const dist_lut *lut, int dx, int dy);

#endif
