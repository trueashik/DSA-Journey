class Solution {
    // Here i have used dp with memoization with TC O(n) and SC O(n)
public:
    int memo(vector<int>& prices, vector<vector<int>>&dp, int idx, int buy){
        if(idx >= prices.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int res;
        if(buy){
            res = max(memo(prices, dp, idx+1, 0)-prices[idx], memo(prices, dp, idx+1, 1));
        }else res = max(memo(prices, dp, idx+2, 1) + prices[idx], memo(prices, dp, idx+1, 0));
        return dp[idx][buy] = res;

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return memo(prices, dp, 0, 1);
        
        
    }
};