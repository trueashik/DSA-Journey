class Solution {
    // Here the TC will be O(n) and SC will be O(1) 
public:
    int maxProduct(vector<int>& nums) {
            int curmax = nums[0];
            int curmin = nums[0];
            int ans = nums[0];
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] < 0) swap(curmax, curmin);
                curmax = max(curmax*nums[i], nums[i]);
                curmin = min(curmin*nums[i], nums[i]);
                ans = max(ans, curmax);
            }
            return ans;
        
    }
};