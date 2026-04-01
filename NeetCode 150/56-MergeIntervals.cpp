class Solution {
    // Here I have used greedy approach with TC O(nlogn) and SC O(1) with output space O(n)
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {        
        int  n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        

        for(int i = 1; i <= n; i++){            
            int x = intervals[i-1][0];
            int y = intervals[i-1][1];
            while (i < n && y >= intervals[i][0]){
                y = max(y, intervals[i][1]);
                i++;
            }
            ans.push_back({x, y});
        }
        return ans;
    }
};