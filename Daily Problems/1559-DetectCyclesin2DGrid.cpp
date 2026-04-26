class Solution {
    // Here I have used dfs approach with TC O(n*m) and SC O(n*m)
public:
    bool checker(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y, int px, int py, char c){
        if(x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0 || grid[x][y] != c) return false;
        if(visited[x][y]) return true;

        visited[x][y] = 1;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto& [dx, dy] : dir){
            int nx = x+dx;
            int ny = y+dy;
            if (nx != px || ny != py){
                if(checker(grid, visited, nx, ny, x, y, c)) return true;
            }            
        }
        return false;
 
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int>>visited (m, vector<int> (n, 0));      
        bool res = false;
        for(int i = 0; i < m && !res; i++){
            for(int j = 0; j < n && !res; j++){\
                if(!visited[i][j]){
                    res = checker(grid, visited, i, j, i, j, grid[i][j]);
                }
                
            }
        }
        return res;        
    }
};