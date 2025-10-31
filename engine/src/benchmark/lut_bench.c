/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lut_bench.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 04:58:22 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:34:46 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<bench.h>
#include<math_extend.h>

void benchmark_lut_trigo(void)
{
    double  start_time;
    double  end_time;
    int     i;
    float   result;
    
    start_time = get_time_ms();
    i = 0;
    while (i < ITERATIONS)
    {
        result = sin_lut(i % 360);
        result = cos_lut(i % 360);
        i++;
    }
    end_time = get_time_ms();
    
    __builtin_printf("LUT (sin_lut + cos_lut): %.3f ms\n", 
                     end_time - start_time);
    (void)result;
}

void benchmark_lut_dist(void)
{
    double  start_time;
    double  end_time;
    int     i;
    float   result;
    int     dx;
    int     dy;
    
    start_time = get_time_ms();
    i = 0;
    while (i < ITERATIONS)
    {
        dx = i % MAX_DIST;
        dy = (i * 7) % MAX_DIST;
        result = get_distance_lut(dx, dy);
        i++;
    }
    end_time = get_time_ms();
    
    __builtin_printf("LUT (get_distance_lut): %.3f ms\n", 
                     end_time - start_time);
    (void)result;
}

void benchmark_lut_sqrtf(void)
{
    double  start_time;
    double  end_time;
    int     i;
    float   result;
    int     value;
    
    start_time = get_time_ms();
    i = 0;
    while (i < ITERATIONS)
    {
        value = i % SQRTF_TABLE_SIZE;
        result = fast_sqrtf_lut(value);
        i++;
    }
    end_time = get_time_ms();
    
    __builtin_printf("LUT (fast_sqrtf_lut): %.3f ms\n", 
                     end_time - start_time);
    (void)result;
}
