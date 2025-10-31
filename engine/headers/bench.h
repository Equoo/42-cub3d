/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 05:00:53 by zsonie            #+#    #+#             */
/*   Updated: 2025/10/31 05:27:15 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# define ITERATIONS 10000000 // 10million

double	get_time_ms(void);

void	display_trigo_benchmark(void);
void	display_dist_benchmark(void);
void	display_sqrtf_benchmark(void);

void	benchmark_lib_trigo(void);
void	benchmark_lut_trigo(void);
void	benchmark_lib_dist(void);
void	benchmark_lut_dist(void);
void	benchmark_lib_sqrtf(void);
void	benchmark_lut_sqrtf(void);

#endif