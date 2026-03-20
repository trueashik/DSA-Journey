class Solution {
    // Here I have used DP with TC O(n*sum) and SC O(sum)
public: 

    int findTargetSumWays(vector<int>& nums, int target) { 
        int sum = 0;
        for(int n : nums) sum+= n;
        if((sum+target)%2 != 0 || abs(target) > sum) return 0;
        int s1 = (sum+target)/2;
        vector<int>dp(s1+1, 0);
        dp[0] = 1;
        for(int i : nums){
            for(int j= s1; j >=i; j--){
                dp[j]+=dp[j - i];
            }
        }
        return dp[s1];
        
    }
};