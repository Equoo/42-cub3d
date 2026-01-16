import unittest
import random
import time
from typing import List

# [Include the fast algorithm functions here]
def largest_rectangle_in_histogram(heights):
    """Find largest rectangle in histogram - O(n) using stack."""
    stack = []
    max_area = 0
    best_rect = None
    index = 0
    
    while index < len(heights):
        if not stack or heights[index] >= heights[stack[-1]]:
            stack.append(index)
            index += 1
        else:
            top = stack.pop()
            width = index if not stack else index - stack[-1] - 1
            area = heights[top] * width
            
            if area > max_area:
                max_area = area
                left = 0 if not stack else stack[-1] + 1
                best_rect = (heights[top], left, width)
    
    while stack:
        top = stack.pop()
        width = index if not stack else index - stack[-1] - 1
        area = heights[top] * width
        
        if area > max_area:
            max_area = area
            left = 0 if not stack else stack[-1] + 1
            best_rect = (heights[top], left, width)
    
    return max_area, best_rect

def find_largest_rectangle_fast(grid):
    """Fast O(rows × cols) algorithm to find largest rectangle."""
    if not grid or not grid[0]:
        return None
    
    rows, cols = len(grid), len(grid[0])
    heights = [0] * cols
    max_area = 0
    best_rect = None
    
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == "empty":
                heights[j] += 1
            else:
                heights[j] = 0
        
        area, rect_info = largest_rectangle_in_histogram(heights)
        
        if area > max_area:
            max_area = area
            if rect_info:
                height, left, width = rect_info
                best_rect = {
                    'top': i - height + 1,
                    'left': left,
                    'bottom': i,
                    'right': left + width - 1,
                    'width': width,
                    'height': height,
                    'area': area
                }
    
    return best_rect

def find_all_maximal_rectangles_fast(grid):
    """Fast iterative approach to find all maximal rectangles."""
    grid_copy = [row[:] for row in grid]
    rectangles = []
    
    while True:
        rect = find_largest_rectangle_fast(grid_copy)
        if rect is None or rect['area'] == 0:
            break
        
        rectangles.append(rect)
        
        for i in range(rect['top'], rect['bottom'] + 1):
            for j in range(rect['left'], rect['right'] + 1):
                grid_copy[i][j] = "full"
    
    return rectangles


# Map Generator
class MapGenerator:
    """Generate test maps with various patterns."""
    
    @staticmethod
    def random_map(rows: int, cols: int, empty_probability: float = 0.7) -> List[List[str]]:
        """Generate a random map.
        
        Args:
            rows: Number of rows
            cols: Number of columns
            empty_probability: Probability of a cell being empty (0.0 to 1.0)
        """
        return [
            ["empty" if random.random() < empty_probability else "full" 
             for _ in range(cols)]
            for _ in range(rows)
        ]
    
    @staticmethod
    def all_empty(rows: int, cols: int) -> List[List[str]]:
        """Generate a completely empty map."""
        return [["empty"] * cols for _ in range(rows)]
    
    @staticmethod
    def all_full(rows: int, cols: int) -> List[List[str]]:
        """Generate a completely full map."""
        return [["full"] * cols for _ in range(rows)]
    
    @staticmethod
    def checkerboard(rows: int, cols: int) -> List[List[str]]:
        """Generate a checkerboard pattern."""
        return [
            ["empty" if (i + j) % 2 == 0 else "full" 
             for j in range(cols)]
            for i in range(rows)
        ]
    
    @staticmethod
    def stripes(rows: int, cols: int, stripe_width: int = 2, 
                horizontal: bool = True) -> List[List[str]]:
        """Generate horizontal or vertical stripes."""
        if horizontal:
            return [
                ["empty" if (i // stripe_width) % 2 == 0 else "full" 
                 for j in range(cols)]
                for i in range(rows)
            ]
        else:
            return [
                ["empty" if (j // stripe_width) % 2 == 0 else "full" 
                 for j in range(cols)]
                for i in range(rows)
            ]
    
    @staticmethod
    def with_rectangles(rows: int, cols: int, num_obstacles: int = 5) -> List[List[str]]:
        """Generate map with random rectangular obstacles."""
        grid = [["empty"] * cols for _ in range(rows)]
        
        for _ in range(num_obstacles):
            r1, r2 = sorted([random.randint(0, rows-1), random.randint(0, rows-1)])
            c1, c2 = sorted([random.randint(0, cols-1), random.randint(0, cols-1)])
            
            for i in range(r1, r2 + 1):
                for j in range(c1, c2 + 1):
                    grid[i][j] = "full"
        
        return grid
    
    @staticmethod
    def sparse_obstacles(rows: int, cols: int, obstacle_count: int = 10) -> List[List[str]]:
        """Generate map with sparse random obstacles."""
        grid = [["empty"] * cols for _ in range(rows)]
        
        for _ in range(min(obstacle_count, rows * cols)):
            r = random.randint(0, rows - 1)
            c = random.randint(0, cols - 1)
            grid[r][c] = "full"
        
        return grid


# Unit Tests
class TestRectangleFinder(unittest.TestCase):
    
    def verify_rectangle(self, grid, rect):
        """Verify that a rectangle is valid and all cells are empty."""
        if rect is None:
            return True
        
        # Check bounds
        self.assertGreaterEqual(rect['top'], 0)
        self.assertGreaterEqual(rect['left'], 0)
        self.assertLess(rect['bottom'], len(grid))
        self.assertLess(rect['right'], len(grid[0]))
        
        # Check dimensions match
        self.assertEqual(rect['height'], rect['bottom'] - rect['top'] + 1)
        self.assertEqual(rect['width'], rect['right'] - rect['left'] + 1)
        self.assertEqual(rect['area'], rect['width'] * rect['height'])
        
        # Check all cells in rectangle are empty
        for i in range(rect['top'], rect['bottom'] + 1):
            for j in range(rect['left'], rect['right'] + 1):
                self.assertEqual(grid[i][j], "empty", 
                               f"Cell ({i},{j}) should be empty in rectangle")
        
        return True
    
    def test_all_empty_grid(self):
        """Test with completely empty grid."""
        grid = MapGenerator.all_empty(5, 5)
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        self.assertEqual(len(rectangles), 1)
        self.assertEqual(rectangles[0]['area'], 25)
        self.assertEqual(rectangles[0]['width'], 5)
        self.assertEqual(rectangles[0]['height'], 5)
    
    def test_all_full_grid(self):
        """Test with completely full grid."""
        grid = MapGenerator.all_full(5, 5)
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        self.assertEqual(len(rectangles), 0)
    
    def test_single_empty_cell(self):
        """Test with single empty cell."""
        grid = MapGenerator.all_full(5, 5)
        grid[2][2] = "empty"
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        self.assertEqual(len(rectangles), 1)
        self.assertEqual(rectangles[0]['area'], 1)
    
    def test_known_configuration(self):
        """Test with a known configuration."""
        grid = [
            ["empty", "empty", "full", "empty", "empty"],
            ["empty", "empty", "full", "empty", "empty"],
            ["empty", "empty", "empty", "empty", "empty"],
            ["full", "empty", "empty", "empty", "full"],
        ]
        
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        # Verify first rectangle is largest
        self.assertGreater(len(rectangles), 0)
        if len(rectangles) > 1:
            self.assertGreaterEqual(rectangles[0]['area'], rectangles[1]['area'])
        
        # Verify all rectangles are valid
        original_grid = [row[:] for row in grid]
        for rect in rectangles:
            self.verify_rectangle(original_grid, rect)
    
    def test_rectangles_dont_overlap(self):
        """Ensure found rectangles don't overlap."""
        grid = MapGenerator.random_map(10, 10, empty_probability=0.8)
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        # Create a coverage map
        coverage = [["empty"] * len(grid[0]) for _ in range(len(grid))]
        
        for rect in rectangles:
            for i in range(rect['top'], rect['bottom'] + 1):
                for j in range(rect['left'], rect['right'] + 1):
                    self.assertEqual(coverage[i][j], "empty", 
                                   "Rectangles should not overlap")
                    coverage[i][j] = "full"
    
    def test_all_empty_cells_covered(self):
        """Ensure all empty cells are covered by rectangles."""
        grid = MapGenerator.random_map(8, 8, empty_probability=0.7)
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        # Count original empty cells
        original_empty = sum(1 for row in grid for cell in row if cell == "empty")
        
        # Count cells covered by rectangles
        covered = sum(rect['area'] for rect in rectangles)
        
        self.assertEqual(original_empty, covered, 
                        "All empty cells should be covered exactly once")
    
    def test_checkerboard_pattern(self):
        """Test with checkerboard pattern."""
        grid = MapGenerator.checkerboard(6, 6)
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        # Each empty cell should be a 1x1 rectangle
        empty_count = sum(1 for row in grid for cell in row if cell == "empty")
        total_area = sum(rect['area'] for rect in rectangles)
        
        self.assertEqual(empty_count, total_area)
    
    def test_empty_grid(self):
        """Test with empty input."""
        self.assertEqual(find_all_maximal_rectangles_fast([]), [])
        self.assertEqual(find_all_maximal_rectangles_fast([[]]), [])
    
    def test_single_row(self):
        """Test with single row."""
        grid = [["empty", "empty", "full", "empty"]]
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        self.assertEqual(len(rectangles), 2)
        areas = sorted([r['area'] for r in rectangles], reverse=True)
        self.assertEqual(areas, [2, 1])
    
    def test_single_column(self):
        """Test with single column."""
        grid = [["empty"], ["empty"], ["full"], ["empty"]]
        rectangles = find_all_maximal_rectangles_fast(grid)
        
        self.assertEqual(len(rectangles), 2)
        areas = sorted([r['area'] for r in rectangles], reverse=True)
        self.assertEqual(areas, [2, 1])


# Performance Tests
class TestPerformance(unittest.TestCase):
    
    def test_small_random_maps(self):
        """Test performance on small random maps."""
        for _ in range(10):
            grid = MapGenerator.random_map(20, 20, empty_probability=0.7)
            start = time.time()
            rectangles = find_all_maximal_rectangles_fast(grid)
            elapsed = time.time() - start
            
            self.assertLess(elapsed, 0.1, "Should complete in < 100ms")
    
    def test_medium_random_maps(self):
        """Test performance on medium random maps."""
        grid = MapGenerator.random_map(100, 100, empty_probability=0.7)
        start = time.time()
        rectangles = find_all_maximal_rectangles_fast(grid)
        elapsed = time.time() - start
        
        print(f"\n100x100 map: {elapsed*1000:.2f}ms, {len(rectangles)} rectangles")
        self.assertLess(elapsed, 1.0, "Should complete in < 1s")
    
    def test_large_random_maps(self):
        """Test performance on large random maps."""
        grid = MapGenerator.random_map(500, 500, empty_probability=0.7)
        start = time.time()
        rectangles = find_all_maximal_rectangles_fast(grid)
        elapsed = time.time() - start
        
        print(f"\n500x500 map: {elapsed*1000:.2f}ms, {len(rectangles)} rectangles")
        self.assertLess(elapsed, 10.0, "Should complete in < 10s")
    
    def test_worst_case_checkerboard(self):
        """Test worst case: checkerboard (many 1x1 rectangles)."""
        grid = MapGenerator.checkerboard(50, 50)
        start = time.time()
        rectangles = find_all_maximal_rectangles_fast(grid)
        elapsed = time.time() - start
        
        print(f"\n50x50 checkerboard: {elapsed*1000:.2f}ms, {len(rectangles)} rectangles")
        self.assertLess(elapsed, 1.0, "Even worst case should be fast")


# Example usage and demonstration
def demonstrate():
    """Demonstrate the rectangle finder with various maps."""
    print("="*60)
    print("Rectangle Finder Demonstration")
    print("="*60)
    
    # Test 1: Small known map
    print("\n1. Small known map:")
    grid = [
        ["empty", "empty", "full", "empty", "empty"],
        ["empty", "empty", "full", "empty", "empty"],
        ["empty", "empty", "empty", "empty", "empty"],
        ["full", "empty", "empty", "empty", "full"],
    ]
    
    rectangles = find_all_maximal_rectangles_fast(grid)
    print(f"   Found {len(rectangles)} rectangles:")
    for i, rect in enumerate(rectangles[:5], 1):
        print(f"   {i}. {rect['width']}×{rect['height']} at ({rect['top']},{rect['left']}) = {rect['area']} cells")
    
    # Test 2: Performance test
    print("\n2. Performance test (1000×1000 random map):")
    large_grid = MapGenerator.random_map(1000, 1000, empty_probability=0.7)
    start = time.time()
    rectangles = find_all_maximal_rectangles_fast(large_grid)
    elapsed = time.time() - start
    print(f"   Time: {elapsed*1000:.2f}ms")
    print(f"   Found {len(rectangles)} rectangles")
    print(f"   Largest: {rectangles[0]['width']}×{rectangles[0]['height']} = {rectangles[0]['area']} cells")


if __name__ == '__main__':
    # Run demonstration
    demonstrate()
    
    print("\n" + "="*60)
    print("Running Unit Tests")
    print("="*60 + "\n")
    
    # Run unit tests
    unittest.main(verbosity=2)
