class Solution {
        // Here I have used recursion with memoization with TC O(m*n) and SC O(m*n)
public:
    int memo(vector<vector<int>>& dp, int x, int y){
        if(x >= dp.size() || y >= dp[0].size()) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        if(x == dp.size()-1 && y == dp[0].size()-1) return 1;
        return dp[x][y] = memo(dp, x+1, y) + memo(dp, x, y+1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memo(dp, 0, 0);
        
    }
};