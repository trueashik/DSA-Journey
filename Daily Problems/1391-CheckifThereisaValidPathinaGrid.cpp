class Solution {
    // I have solved this problem using recursion with memoization with TC O(n*m) and SC O(n*m)
public:
    vector<vector<vector<int>>>dirs = {
        {},
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{1, 0}, {0, 1}},
        {{0, -1}, {-1, 0}},
        {{0, 1}, {-1, 0}}
    };
    bool recurse(vector<vector<int>>& grid,vector<vector<int>>& visited, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        if(x == m-1 && y == n-1) return true;
        
        visited[x][y] = 1;
        for(auto& d : dirs[grid[x][y]]){
            int nx = x+d[0], ny = y+d[1];
            if(nx >= m || ny >= n || nx < 0 || ny < 0 || visited[nx][ny]) continue;
            for(auto& back : dirs[grid[nx][ny]]){
                if(nx+back[0] == x && ny +back[1] == y){
                    if(recurse(grid, visited, nx, ny)) return true;
                }
            }

        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(), 0));

         return recurse(grid, visited, 0, 0);
    }
};