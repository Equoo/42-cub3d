/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bench.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 04:58:03 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:47:36 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<bench.h>
#include<math_extend.h>

void benchmark_lib_trigo(void)
{
    double  start_time;
    double  end_time;
    int     i;
    float   result;
    float   radians;
    
    start_time = get_time_ms();
    i = 0;
    while (i < ITERATIONS)
    {
        radians = (i % 360) * (PI / 180.0);
        result = sin(radians);
        result = cos(radians);
        i++;
    }
    end_time = get_time_ms();
    
    __builtin_printf("Math.h (sin + cos): %.3f ms\n", 
                     end_time - start_time);
    (void)result;
}

void benchmark_lib_dist(void)
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
        result = sqrtf((float)(dx * dx + dy * dy));
        i++;
    }
    end_time = get_time_ms();
    
    __builtin_printf("Math.h (sqrtf): %.3f ms\n", 
                     end_time - start_time);
    (void)result;
}

void benchmark_lib_sqrtf(void)
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
        result = sqrtf((float)value);
        i++;
    }
    end_time = get_time_ms();
    
    __builtin_printf("Math.h (sqrtf): %.3f ms\n", 
                     end_time - start_time);
    (void)result;
}
