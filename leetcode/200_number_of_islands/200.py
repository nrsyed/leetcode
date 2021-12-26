class Solution:
    def bfs(self, grid, x, y, visited):
        queue = [(x, y)]
        
        while queue:
            x, y = queue.pop(0)
            
            for (dx, dy) in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                x2 = x + dx
                y2 = y + dy
                
                if (
                    (0 <= x2 < len(grid[0]))
                    and (0 <= y2 < len(grid))
                    and (not visited[y2][x2])
                ):
                    visited[y2][x2] = True
                    
                    if grid[y2][x2] == "1":
                        queue.append((x2, y2))
    
    def numIslands(self, grid: List[List[str]]) -> int:
        nrows = len(grid)
        ncols = len(grid[0])
        visited = [[False for _ in range(ncols)] for _ in range(nrows)]
        
        num_islands = 0
        
        for y in range(nrows):
            for x in range(ncols):
                if not visited[y][x]:
                    visited[y][x] = True
                    
                    if grid[y][x] == "1":
                        self.bfs(grid, x, y, visited)
                        num_islands += 1
                        
        return num_islands
