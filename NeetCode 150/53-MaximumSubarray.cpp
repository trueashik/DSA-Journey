class Solution {
    // Here I have used Kadane's algorithm with TC O(n) and SC O(1)
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curr = max(nums[i], curr+nums[i]);
            res = max(res, curr);
        }
        return res;                
    }
};