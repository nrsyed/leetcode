class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        grid = [[0 for _ in range(n)] for _ in range(m)]
        grid[0][0] = 1
        
        for i in range(m):
            for j in range(n):
                if i > 0:
                    grid[i][j] += grid[i-1][j]
                if j > 0:
                    grid[i][j] += grid[i][j-1]
        return grid[-1][-1]
