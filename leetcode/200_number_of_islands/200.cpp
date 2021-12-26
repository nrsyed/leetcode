class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.emplace(j, i);
        grid[i][j] = '2';
        
        vector<pair<int, int>> directions {
            make_pair(1, 0),
            make_pair(0, 1),
            make_pair(-1, 0),
            make_pair(0, -1)
        };
        
        while (!q.empty()) {
            auto node {q.front()};
            q.pop();
            
            for (pair<int, int> direction : directions) {
                int new_x {node.first + direction.first};
                int new_y {node.second + direction.second};
                
                if (
                    new_x >= 0 && new_x < grid[0].size()
                    && new_y >= 0 && new_y < grid.size()
                    && grid[new_y][new_x] == '1'
                ) {
                    q.emplace(new_x, new_y);
                    grid[new_y][new_x] = '2';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int num_islands {0};
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    num_islands++;
                } else {
                    grid[i][j] = '2';
                }
            }
        }
        return num_islands;
    }
};
