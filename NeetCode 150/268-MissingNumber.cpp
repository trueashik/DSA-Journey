class Solution {
    // Here it is solved using Math with TC and SC O(1)
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()*(nums.size()+1)/2;
        for(int i : nums){
            n-=i;
        }
        return n;
        
    }
};