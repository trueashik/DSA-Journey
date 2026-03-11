class Solution {
    // Here the TC will be O(n*t) and SC will be O(t) and it is a top down approach
public:
    int dfs(vector<int>& coins, int amount, vector<int>& dp){
        if(amount < 0) return INT_MAX - 1;
        if(amount == 0) return 0;
        if(dp[amount] != INT_MAX) return dp[amount];
        int ans = INT_MAX - 1;
        for(int i : coins){
            int res = dfs(coins, amount-i, dp);
            ans = min(res!=INT_MAX ? 1+res : res, ans);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount+1, INT_MAX);
       int res = dfs(coins, amount, dp);
       if(res >= INT_MAX-1) return -1;
       return res;

    }
};