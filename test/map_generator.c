// map_generator.c
#include "map_generator.h"
#include "rectangle_finder.h"
#include <stdlib.h>
#include <time.h>

static int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

int** generate_random_map(int rows, int cols, double empty_probability) {
    int** grid = create_grid(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = ((double)rand() / RAND_MAX) < empty_probability ? 0 : 1;
        }
    }
    
    return grid;
}

int** generate_all_empty(int rows, int cols) {
    int** grid = create_grid(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
    
    return grid;
}

int** generate_all_full(int rows, int cols) {
    int** grid = create_grid(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 1;
        }
    }
    
    return grid;
}

int** generate_checkerboard(int rows, int cols) {
    int** grid = create_grid(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (i + j) % 2;
        }
    }
    
    return grid;
}

int** generate_stripes(int rows, int cols, int stripe_width, int horizontal) {
    int** grid = create_grid(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (horizontal) {
                grid[i][j] = (i / stripe_width) % 2;
            } else {
                grid[i][j] = (j / stripe_width) % 2;
            }
        }
    }
    
    return grid;
}

int** generate_with_rectangles(int rows, int cols, int num_obstacles) {
    int** grid = generate_all_empty(rows, cols);
    
    for (int n = 0; n < num_obstacles; n++) {
        int r1 = rand_range(0, rows - 1);
        int r2 = rand_range(0, rows - 1);
        int c1 = rand_range(0, cols - 1);
        int c2 = rand_range(0, cols - 1);
        
        if (r1 > r2) { int tmp = r1; r1 = r2; r2 = tmp; }
        if (c1 > c2) { int tmp = c1; c1 = c2; c2 = tmp; }
        
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                grid[i][j] = 1;
            }
        }
    }
    
    return grid;
}

int** generate_sparse_obstacles(int rows, int cols, int obstacle_count) {
    int** grid = generate_all_empty(rows, cols);
    
    int max_obstacles = rows * cols;
    if (obstacle_count > max_obstacles) {
        obstacle_count = max_obstacles;
    }
    
    for (int n = 0; n < obstacle_count; n++) {
        int r = rand_range(0, rows - 1);
        int c = rand_range(0, cols - 1);
        grid[r][c] = 1;
    }
    
    return grid;
}
