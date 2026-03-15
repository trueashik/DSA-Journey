class Solution {
    // It is a recursion with memoization approach with TC O(n*target) and SC O(n*target)
public:
    int dfs(vector<int>& nums, int idx, int n, vector<vector<int>>& dp){
        if(n == 0)return 1;
        if(idx >= nums.size() || n < 0) return 0;
        if(dp[idx][n] != -1) return dp[idx][n];
        
        dp[idx][n] = dfs(nums, idx+1, n - nums[idx], dp) || dfs(nums, idx+1, n, dp);
        return dp[idx][n];

    }
    bool canPartition(vector<int>& nums) {
        int total = 0;      
        for(int i : nums)total+=i;
        if(total%2 != 0) return false;       
        total/=2;
        vector<vector<int>> dp(nums.size(), vector<int>(total+1, -1));

        
        return dfs(nums, 0, total, dp);
        
    }
};