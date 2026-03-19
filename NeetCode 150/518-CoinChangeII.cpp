class Solution {
    // here I have used recursion with memoization with TC O(n*amount) and SC O(n*amount)a
public:
    int memo(vector<int>& coins, int n, vector<vector<int>>&dp, int idx){
        if(n == 0) return 1;
        if(n < 0 || idx >= coins.size()) return 0;
        if(dp[idx][n] != -1) return dp[idx][n];
        int res = 0;
        res+=memo(coins, n-coins[idx], dp, idx);
        res+=memo(coins, n, dp, idx+1);
        return dp[idx][n] = res;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        return memo(coins, amount, dp, 0);
    }
};