// rectangle_finder.c
#include "rectangle_finder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Stack;

static Stack* stack_create(size_t initial_capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = initial_capacity;
    s->size = 0;
    s->data = (int*)malloc(initial_capacity * sizeof(int));
    return s;
}

static void stack_free(Stack* s) {
    free(s->data);
    free(s);
}

static void stack_push(Stack* s, int value) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
    }
    s->data[s->size++] = value;
}

static int stack_pop(Stack* s) {
    return s->data[--s->size];
}

static int stack_is_empty(const Stack* s) {
    return s->size == 0;
}

static int stack_top(const Stack* s) {
    return s->data[s->size - 1];
}

typedef struct {
    int area;
    int height;
    int left;
    int width;
} HistogramResult;

static HistogramResult largest_rectangle_in_histogram(int* heights, int size) {
    Stack* stack = stack_create(size);
    HistogramResult result = {0, 0, 0, 0};
    int index = 0;
    
    while (index < size) {
        if (stack_is_empty(stack) || heights[index] >= heights[stack_top(stack)]) {
            stack_push(stack, index);
            index++;
        } else {
            int top = stack_pop(stack);
            int width = stack_is_empty(stack) ? index : index - stack_top(stack) - 1;
            int area = heights[top] * width;
            
            if (area > result.area) {
                result.area = area;
                result.height = heights[top];
                result.left = stack_is_empty(stack) ? 0 : stack_top(stack) + 1;
                result.width = width;
            }
        }
    }
    
    while (!stack_is_empty(stack)) {
        int top = stack_pop(stack);
        int width = stack_is_empty(stack) ? index : index - stack_top(stack) - 1;
        int area = heights[top] * width;
        
        if (area > result.area) {
            result.area = area;
            result.height = heights[top];
            result.left = stack_is_empty(stack) ? 0 : stack_top(stack) + 1;
            result.width = width;
        }
    }
    
    stack_free(stack);
    return result;
}

Rectangle* find_largest_rectangle(int** grid, int rows, int cols) {
    if (!grid || rows <= 0 || cols <= 0) {
        return NULL;
    }
    
    int* heights = (int*)calloc(cols, sizeof(int));
    Rectangle* best_rect = NULL;
    int max_area = 0;
    
    for (int i = 0; i < rows; i++) {
        // Update heights for current row
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0) {  // 0 = empty
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        
        // Find largest rectangle in this histogram
        HistogramResult hist_result = largest_rectangle_in_histogram(heights, cols);
        
        if (hist_result.area > max_area) {
            max_area = hist_result.area;
            
            if (best_rect == NULL) {
                best_rect = (Rectangle*)malloc(sizeof(Rectangle));
            }
            
            best_rect->height = hist_result.height;
            best_rect->width = hist_result.width;
            best_rect->left = hist_result.left;
            best_rect->top = i - hist_result.height + 1;
            best_rect->bottom = i;
            best_rect->right = hist_result.left + hist_result.width - 1;
            best_rect->area = hist_result.area;
        }
    }
    
    free(heights);
    return best_rect;
}

static void fill_rectangle(int** grid, const Rectangle* rect) {
    for (int i = rect->top; i <= rect->bottom; i++) {
        for (int j = rect->left; j <= rect->right; j++) {
            grid[i][j] = 1;  // 1 = full
        }
    }
}

RectangleList* find_all_maximal_rectangles(int** grid, int rows, int cols) {
    // Create a copy of the grid
    int** grid_copy = create_grid(rows, cols);
    for (int i = 0; i < rows; i++) {
        memcpy(grid_copy[i], grid[i], cols * sizeof(int));
    }
    
    RectangleList* list = (RectangleList*)malloc(sizeof(RectangleList));
    list->capacity = 16;
    list->count = 0;
    list->rects = (Rectangle*)malloc(list->capacity * sizeof(Rectangle));
    
    while (1) {
        Rectangle* rect = find_largest_rectangle(grid_copy, rows, cols);
        
        if (rect == NULL || rect->area == 0) {
            free(rect);
            break;
        }
        
        // Add to list
        if (list->count >= list->capacity) {
            list->capacity *= 2;
            list->rects = (Rectangle*)realloc(list->rects, list->capacity * sizeof(Rectangle));
        }
        
        list->rects[list->count++] = *rect;
        
        // Fill the rectangle in the copy
        fill_rectangle(grid_copy, rect);
        
        free(rect);
    }
    
    free_grid(grid_copy, rows);
    return list;
}

// Helper functions
int** create_grid(int rows, int cols) {
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
    }
    return grid;
}

void free_grid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

void free_rectangle(Rectangle* rect) {
    free(rect);
}

void free_rectangle_list(RectangleList* list) {
    free(list->rects);
    free(list);
}

void print_rectangle(const Rectangle* rect) {
    printf("Rectangle: %dx%d at (%d,%d) to (%d,%d) = %d cells\n",
           rect->width, rect->height, rect->top, rect->left,
           rect->bottom, rect->right, rect->area);
}

void print_grid(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}
