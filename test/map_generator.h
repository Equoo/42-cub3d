// map_generator.h
#ifndef MAP_GENERATOR_H
#define MAP_GENERATOR_H

// Map generation functions
int** generate_random_map(int rows, int cols, double empty_probability);
int** generate_all_empty(int rows, int cols);
int** generate_all_full(int rows, int cols);
int** generate_checkerboard(int rows, int cols);
int** generate_stripes(int rows, int cols, int stripe_width, int horizontal);
int** generate_with_rectangles(int rows, int cols, int num_obstacles);
int** generate_sparse_obstacles(int rows, int cols, int obstacle_count);

#endif // MAP_GENERATOR_H
