/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_lerp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:39:34 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 00:58:27 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

float	lerp(float v0, float v1, float t)
{
	return (v0 + t * (v1 - v0));
}

/* 
    Precise method, which guarantees v = v1 when t = 1.
    This method is monotonic only when v0 * v1 < 0.
    Lerping between same values might not produce the same value
*/
float	precise_lerp(float v0, float v1, float t)
{
	return ((1 - t) * v0 + t * v1);
}
