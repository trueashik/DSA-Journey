class Solution {
    // Here I have used median approach with TC O(n log n) and SC O(n)
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        int rem = grid[0][0]%x;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                nums.push_back(grid[i][j]);   
                if(rem != grid[i][j]%x) return -1;  
            }
        }
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];
        int res = 0;
        for(int i : nums){
            res+= abs(i - median)/x;
        }
        return res;
         
        
    }
};