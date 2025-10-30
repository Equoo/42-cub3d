/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:40:53 by dderny            #+#    #+#             */
/*   Updated: 2025/10/30 04:11:45 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <types/mat2.h>

// Imprecise method, which does not guarantee v = v1 when t = 1, due to floating-point arithmetic error.
// This method is monotonic. This form may be used when the hardware has a native fused multiply-add instruction.
// Source wikipedia linear interpolation
float lerp(float v0, float v1, float t) {
  return v0 + t * (v1 - v0);
}

// Precise method, which guarantees v = v1 when t = 1. This method is monotonic only when v0 * v1 < 0.
// Lerping between same values might not produce the same value
// Source wikipedia linear interpolation
float precise_lerp(float v0, float v1, float t) {
  return (1 - t) * v0 + t * v1;
}
