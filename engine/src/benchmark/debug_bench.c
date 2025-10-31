/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 05:05:45 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:37:19 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bench.h>
#include <math_extend.h>
#include <stdlib.h>
#include <sys/time.h>

double	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

void	display_trigo_benchmark(void)
{
	__builtin_printf("\n\n");
	__builtin_printf("Benchmark: %d iterations\n\n", ITERATIONS);
	// Premier appel pour initialiser les tables LUT
	sin_lut(0);
	cos_lut(0);
	__builtin_printf("Test 1:\n");
	benchmark_lut_trigo();
	benchmark_lib_trigo();
	__builtin_printf("\nTest 2 (verification):\n");
	benchmark_lib_trigo();
	benchmark_lut_trigo();
}

void	display_dist_benchmark(void)
{
	__builtin_printf("\n\n");
	__builtin_printf("Benchmark: %d iterations\n", ITERATIONS);
	__builtin_printf("MAX_DIST: %d\n\n", MAX_DIST);
	// Premier appel pour initialiser la table LUT
	get_distance_lut(0, 0);
	__builtin_printf("Test 1:\n");
	benchmark_lut_dist();
	benchmark_lib_dist();
	__builtin_printf("\nTest 2 (verification):\n");
	benchmark_lib_dist();
	benchmark_lut_dist();
}

void	display_sqrtf_benchmark(void)
{
	__builtin_printf("\n\n");
	__builtin_printf("Benchmark: %d iterations\n", ITERATIONS);
	__builtin_printf("SQRTF_TABLE_SIZE: %d\n\n", SQRTF_TABLE_SIZE);
	// Premier appel pour initialiser la table LUT
	fast_sqrtf_lut(0);
	__builtin_printf("Test 1:\n");
	benchmark_lut_sqrtf();
	benchmark_lib_sqrtf();
	__builtin_printf("\nTest 2 (verification):\n");
	benchmark_lib_sqrtf();
	benchmark_lut_sqrtf();
}
