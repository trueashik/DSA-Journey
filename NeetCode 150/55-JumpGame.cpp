class Solution {
     // Here I have used greedy approach with TC O(n) and SC O(1)
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        int goal = n-1;
        for(int i = n-2 ; i>=0; i--){
            if(nums[0] >= goal) return true;
            if(nums[i] >= goal -i) goal = i;
        }
        return false;
        
    }
};