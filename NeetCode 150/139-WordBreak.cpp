class Solution {
    // Here I have used recursion with memoization with TC O(n*n*m) and SC O(n)
public:
    
    int brute(unordered_set<string>& st, string&s, int idx, vector<int>& dp){
        if(idx > s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        if(idx == s.size()) return dp[idx] = 1;
        
        for(auto& k : st){
            if(st.count(s.substr(idx, k.size()))){
                dp[idx] = brute(st, s, idx + k.size(), dp);
                if(dp[idx] == 1){
                    return 1;
                }

            } 
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<int>dp(s.size()+1, -1);
        for(string& k : wordDict) st.insert(k);        
        return brute(st, s, 0, dp);

        
    }
};