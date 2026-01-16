// rectangle_finder.h
#ifndef RECTANGLE_FINDER_H
#define RECTANGLE_FINDER_H

#include <stddef.h>

typedef struct {
    int top;
    int left;
    int bottom;
    int right;
    int width;
    int height;
    int area;
} Rectangle;

typedef struct {
    Rectangle* rects;
    size_t count;
    size_t capacity;
} RectangleList;

// Core functions
Rectangle* find_largest_rectangle(int** grid, int rows, int cols);
RectangleList* find_all_maximal_rectangles(int** grid, int rows, int cols);

// Helper functions
int** create_grid(int rows, int cols);
void free_grid(int** grid, int rows);
void free_rectangle(Rectangle* rect);
void free_rectangle_list(RectangleList* list);
void print_rectangle(const Rectangle* rect);
void print_grid(int** grid, int rows, int cols);

#endif // RECTANGLE_FINDER_H
