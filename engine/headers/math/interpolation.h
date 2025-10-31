/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:37:59 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 00:58:45 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPOLATION_H
# define INTERPOLATION_H

float	lerp(float v0, float v1, float t);
float	precise_lerp(float v0, float v1, float t);

float	easeInSine(int x);
float	easeOutSine(int x);
float	easeInOutSine(int x);

float	easeInCubic(int x);
float	easeOutCubic(int x);
float	easeInOutCubic(int x);

#endif
