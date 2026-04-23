class Solution {
    // It solved by using the prefix sum approach with TC O(n) and SC O(n)
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>arr(n, 0);
        unordered_map<int, vector<int>> ump;
        for(int i = 0; i < n; i++){
            ump[nums[i]].push_back(i);
        }
        for(auto& m:ump){
            vector<int> &idx = m.second;
            int sz = idx.size(), total = 0;
            vector<long long>prefix(sz, 0);
            prefix[0] = idx[0];
            for(int i = 1; i < sz; i++){
                prefix[i] = prefix[i-1]+idx[i];
            }
            for(int i = 0; i < sz;i++){
                long long left = (long long)idx[i]*i - (i > 0 ? prefix[i-1] : 0);
                long long right = (prefix[sz-1]-prefix[i]) - idx[i]*(long long)(sz-i-1);
                arr[idx[i]] = left+right;
            }
        }
        return arr;
        
    }
};
