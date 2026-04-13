class Solution {
    // Solved using Bit Manipulation in O(n) TC and O(1) SC
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            res ^= nums[i];
        }
        return res;
        
    }
};