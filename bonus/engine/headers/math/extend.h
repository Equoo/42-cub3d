/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:29:53 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 22:04:33 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTEND_H
# define EXTEND_H

# include <math.h>

# define TABLE_SIZE 3600        // trigo
# define MAX_DIST 10000         // dist
# define SQRTF_TABLE_SIZE 10000 // sqrtf

# define EPSILON 0.0001
# define PI 3.141592

float	sin_lut(float angle_deg);
float	cos_lut(float angle_deg);

float	get_distance_lut(int dx, int dy);

float	fast_sqrtf_lut(int value);

float	sanitize_angle(float f);

#endif
