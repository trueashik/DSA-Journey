class Solution {
    // Here I have used greedy approach with TC O(n) and SC O(1)
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int> last(27);
        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i;
        }
        int curr = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            curr++;
            int idx = last[s[i] - 'a'];
            if(idx > end) end = idx;
            if(end == i){
                ans.push_back(curr);
                curr = 0;
                continue;
            }
            
        } 
        return ans;   
        
        
    }
};