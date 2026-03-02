class Solution {
    //Here the TC and SC will be O(n)
public:
    int dfs(vector<int>& nums, int idx, vector<int>& dp, int end){
        if(idx > end) return 0;
        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + dfs(nums, idx+2, dp, end);
        int skip = dfs(nums, idx+1, dp, end);

        
        return dp[idx] = max(take, skip);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        if (n == 1) return nums[0];
        

        return max(dfs(nums, 0, dp1, n-2), dfs(nums, 1, dp2, n-1));
        
    }
};