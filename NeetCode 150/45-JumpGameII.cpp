class Solution {
    // Here I have used greedy approach with TC O(n) and SC O(1)
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        int maxjump = 0;
        for(int i = 0; i < nums.size()-1; i++){
            maxjump = max(maxjump, i + nums[i]);
            if(i == curr){
                curr = maxjump;
                ans++;
            }
        }
        return ans;
        
        
    }
    
};