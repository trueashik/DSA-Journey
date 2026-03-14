class Solution {
    // Here I have used Top-Down Dp with TC O(n^2) and SC O(n)
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        int n = nums.size();
        int res = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            res = max(dp[i], res);
        }
        return res;
        
    }
};