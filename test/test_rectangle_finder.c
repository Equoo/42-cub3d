// test_rectangle_finder.c
#include "rectangle_finder.h"
#include "map_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define TEST_PASSED printf("  ✓ PASSED\n")
#define TEST_FAILED printf("  ✗ FAILED\n")

static int tests_passed = 0;
static int tests_failed = 0;

static void verify_rectangle(int** grid, int rows, int cols, const Rectangle* rect) {
    assert(rect->top >= 0);
    assert(rect->left >= 0);
    assert(rect->bottom < rows);
    assert(rect->right < cols);
    assert(rect->height == rect->bottom - rect->top + 1);
    assert(rect->width == rect->right - rect->left + 1);
    assert(rect->area == rect->width * rect->height);
    
    // Verify all cells are empty (0)
    for (int i = rect->top; i <= rect->bottom; i++) {
        for (int j = rect->left; j <= rect->right; j++) {
            assert(grid[i][j] == 0);
        }
    }
}

static void test_all_empty_grid() {
    printf("Test: All empty grid... ");
    
    int** grid = generate_all_empty(5, 5);
    RectangleList* rects = find_all_maximal_rectangles(grid, 5, 5);
    
    assert(rects->count == 1);
    assert(rects->rects[0].area == 25);
    assert(rects->rects[0].width == 5);
    assert(rects->rects[0].height == 5);
    
    free_rectangle_list(rects);
    free_grid(grid, 5);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_all_full_grid() {
    printf("Test: All full grid... ");
    
    int** grid = generate_all_full(5, 5);
    RectangleList* rects = find_all_maximal_rectangles(grid, 5, 5);
    
    assert(rects->count == 0);
    
    free_rectangle_list(rects);
    free_grid(grid, 5);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_single_empty_cell() {
    printf("Test: Single empty cell... ");
    
    int** grid = generate_all_full(5, 5);
    grid[2][2] = 0;
    
    RectangleList* rects = find_all_maximal_rectangles(grid, 5, 5);
    
    assert(rects->count == 1);
    assert(rects->rects[0].area == 1);
    
    free_rectangle_list(rects);
    free_grid(grid, 5);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_known_configuration() {
    printf("Test: Known configuration... ");
    
    int** grid = create_grid(4, 5);
    int data[4][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1}
    };
    
    for (int i = 0; i < 4; i++) {
        memcpy(grid[i], data[i], 5 * sizeof(int));
    }
    
    RectangleList* rects = find_all_maximal_rectangles(grid, 4, 5);
    
    assert(rects->count > 0);
    
    // Verify rectangles are sorted by area (largest first)
    for (size_t i = 1; i < rects->count; i++) {
        assert(rects->rects[i-1].area >= rects->rects[i].area);
    }
    
    free_rectangle_list(rects);
    free_grid(grid, 4);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_rectangles_dont_overlap() {
    printf("Test: Rectangles don't overlap... ");
    
    int** grid = generate_random_map(10, 10, 0.8);
    RectangleList* rects = find_all_maximal_rectangles(grid, 10, 10);
    
    // Create coverage map
    int** coverage = generate_all_empty(10, 10);
    
    for (size_t n = 0; n < rects->count; n++) {
        Rectangle* rect = &rects->rects[n];
        for (int i = rect->top; i <= rect->bottom; i++) {
            for (int j = rect->left; j <= rect->right; j++) {
                assert(coverage[i][j] == 0);  // Should not be covered yet
                coverage[i][j] = 1;
            }
        }
    }
    
    free_grid(coverage, 10);
    free_rectangle_list(rects);
    free_grid(grid, 10);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_all_empty_cells_covered() {
    printf("Test: All empty cells covered... ");
    
    int** grid = generate_random_map(8, 8, 0.7);
    
    // Count original empty cells
    int original_empty = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == 0) original_empty++;
        }
    }
    
    RectangleList* rects = find_all_maximal_rectangles(grid, 8, 8);
    
    // Count cells covered by rectangles
    int covered = 0;
    for (size_t n = 0; n < rects->count; n++) {
        covered += rects->rects[n].area;
    }
    
    assert(original_empty == covered);
    
    free_rectangle_list(rects);
    free_grid(grid, 8);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_checkerboard_pattern() {
    printf("Test: Checkerboard pattern... ");
    
    int** grid = generate_checkerboard(6, 6);
    RectangleList* rects = find_all_maximal_rectangles(grid, 6, 6);
    
    // Count empty cells
    int empty_count = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (grid[i][j] == 0) empty_count++;
        }
    }
    
    // Calculate total area
    int total_area = 0;
    for (size_t n = 0; n < rects->count; n++) {
        total_area += rects->rects[n].area;
    }
    
    assert(empty_count == total_area);
    
    free_rectangle_list(rects);
    free_grid(grid, 6);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_performance_small() {
    printf("Test: Performance (20x20)... ");
    
    clock_t start = clock();
    
    for (int iter = 0; iter < 10; iter++) {
        int** grid = generate_random_map(20, 20, 0.7);
        RectangleList* rects = find_all_maximal_rectangles(grid, 20, 20);
        free_rectangle_list(rects);
        free_grid(grid, 20);
    }
    
    clock_t end = clock();
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("%.2fms avg ", elapsed * 100);
    assert(elapsed < 1.0);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_performance_medium() {
    printf("Test: Performance (100x100)... ");
    
    int** grid = generate_random_map(100, 100, 0.7);
    
    clock_t start = clock();
    RectangleList* rects = find_all_maximal_rectangles(grid, 100, 100);
    clock_t end = clock();
    
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("%.2fms, %zu rects ", elapsed * 1000, rects->count);
    assert(elapsed < 1.0);
    
    free_rectangle_list(rects);
    free_grid(grid, 100);
    
    tests_passed++;
    TEST_PASSED;
}

static void test_performance_large() {
    printf("Test: Performance (500x500)... ");
    
    int** grid = generate_random_map(500, 500, 0.7);
    
    clock_t start = clock();
    RectangleList* rects = find_all_maximal_rectangles(grid, 500, 500);
    clock_t end = clock();
    
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("%.2fms, %zu rects ", elapsed * 1000, rects->count);
    assert(elapsed < 10.0);
    
    free_rectangle_list(rects);
    free_grid(grid, 500);
    
    tests_passed++;
    TEST_PASSED;
}

void run_all_tests() {
    printf("\n");
    printf("==========================================================\n");
    printf("Running Rectangle Finder Unit Tests\n");
    printf("==========================================================\n\n");
    
    test_all_empty_grid();
    test_all_full_grid();
    test_single_empty_cell();
    test_known_configuration();
    test_rectangles_dont_overlap();
    test_all_empty_cells_covered();
    test_checkerboard_pattern();
    
    printf("\n");
    printf("==========================================================\n");
    printf("Running Performance Tests\n");
    printf("==========================================================\n\n");
    
    test_performance_small();
    test_performance_medium();
    test_performance_large();
    
    printf("\n");
    printf("==========================================================\n");
    printf("Test Results: %d passed, %d failed\n", tests_passed, tests_failed);
    printf("==========================================================\n\n");
}

int main() {
    srand(time(NULL));
    
    // Run tests
    run_all_tests();
    
    // Demonstration
    printf("==========================================================\n");
    printf("Demonstration\n");
    printf("==========================================================\n\n");
    
    printf("Small known map:\n");
    int** demo_grid = create_grid(4, 5);
    int demo_data[4][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1}
    };
    
    for (int i = 0; i < 4; i++) {
        memcpy(demo_grid[i], demo_data[i], 5 * sizeof(int));
    }
    
    print_grid(demo_grid, 4, 5);
    printf("\n");
    
    RectangleList* demo_rects = find_all_maximal_rectangles(demo_grid, 4, 5);
    
    printf("Found %zu rectangles:\n", demo_rects->count);
    for (size_t i = 0; i < demo_rects->count && i < 5; i++) {
        printf("%zu. ", i + 1);
        print_rectangle(&demo_rects->rects[i]);
    }
    
    free_rectangle_list(demo_rects);
    free_grid(demo_grid, 4);
    
    return 0;
}
