class Solution {
    // Here I have used recursion with memoization with TC O(n*m*k) and SC O(n*m*k)
public:
    int cms(vector<vector<int>>& grid, int x, int y, int k, vector<vector<vector<int>>>& dp) {
        int m = grid.size(), n = grid[0].size();
        
        if (x >= m || y >= n) return -1; 
        
        int val = grid[x][y];
        int next_k = val ? k - 1 : k; 
        if (next_k < 0) return -1;
        if (x == m - 1 && y == n - 1) return val;
        if (dp[x][y][k] != -2) return dp[x][y][k];
        
        int right = cms(grid, x, y + 1, next_k, dp);
        int down = cms(grid, x + 1, y, next_k, dp);
        
        int max_next = max(right, down);
        
        if (max_next == -1) return dp[x][y][k] = -1;
        
        return dp[x][y][k] = val + max_next;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
      
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -2)));
        
        return cms(grid, 0, 0, k, dp);
    }
};