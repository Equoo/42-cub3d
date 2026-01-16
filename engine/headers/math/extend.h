/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_extend.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:29:53 by dderny            #+#    #+#             */
/*   Updated: 2025/10/31 05:27:07 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_EXTEND_H
# define MATH_EXTEND_H

# include <math.h>

# define EPSILON 0.0001
# define PI 3.141592

# define TABLE_SIZE 3600 //trigo
float	sin_lut(float angle_deg);
float	cos_lut(float angle_deg);

# define MAX_DIST 10000 //dist
float	get_distance_lut(int dx, int dy);

# define SQRTF_TABLE_SIZE 10000 //sqrtf
float	fast_sqrtf_lut(int value);

#endif



// to check: les instructions SIMD sont apparement plutot rapide pour sqrt donc a verifier
// si il y a gain de perf ou non
// "Pour le raycasting,
//	la table compacte combinée avec l'approximation rapide est souvent la meilleure option."


/*
#define SQRT_TABLE_SIZE 1024

typedef struct {
	float sqrt_table[SQRT_TABLE_SIZE];
}				CompactSqrtLUT;

float	fast_inv_sqrt(float number) {
	int32_t i;
	float x2, y;
	const float threehalfs = 1.5f;

	x2 = number * 0.5f;
	y = number;
	i = *(int32_t*)&y;                      // Evil bit hack
	i = 0x5f3759df - (i >> 1);              // Magic constant
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));   // 1 iteration Newton-Raphson

	return (y);
}

float	fast_sqrt_approx(float number) {
	if (number == 0.0f) return (0.0f);
	return (number * fast_inv_sqrt(number));
}
CompactSqrtLUT* create_compact_sqrt_lut(void) {
	CompactSqrtLUT* lut = malloc(sizeof(CompactSqrtLUT));
	if (!lut) return (NULL);

	for (int i = 0; i < SQRT_TABLE_SIZE; i++) {
		lut->sqrt_table[i] = sqrtf((float)i);
	}

	return (lut);
}

Calcul de distance optimisé avec LUT partielle
float	fast_distance(const CompactSqrtLUT* lut, int dx, int dy) {
	int dist_squared = dx * dx + dy * dy;

	if (dist_squared < SQRT_TABLE_SIZE) {
		return (lut->sqrt_table[dist_squared]);
	}

	// Pour grandes distances, utiliser approximation rapide
	return (fast_sqrt_approx((float)dist_squared));
}

https://en.wikipedia.org/wiki/Fast_inverse_square_root used in Quake 3

Cette approche hybride est optimale pour le raycasting car:

Table compacte (petites valeurs): Pour les distances courtes et moyennes (les plus fréquentes dans un raycasting),
	vous utilisez une lookup table de taille raisonnable (1024 entrées = 4 KB seulement). Cela couvre les calculs les plus critiques avec une précision parfaite.​

Approximation rapide (grandes valeurs): Pour les distances plus éloignées (moins fréquentes et souvent moins visibles),
	vous utilisez l'approximation rapide type Quake III (fast_inv_sqrt). Comme ces objets sont loin,
	la légère perte de précision n'est pas visible à l'écran.​

Avantages combinés: Vous obtenez une consommation mémoire très faible (contrairement à une table géante 3D qui prendrait des mégaoctets),
	une performance excellente pour les cas courants,
	et un fallback rapide pour les cas rares. C'est exactement le type d'optimisation utilisée dans les moteurs de raycasting classiques comme Wolfenstein 3D.​

Cette solution est bien meilleure qu'une table complète (trop de mémoire) ou qu'une approximation pure (perte de précision sur les distances proches qui sont les plus importantes visuellement).
*/
