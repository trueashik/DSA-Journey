class Solution {
// with dp it is O(n) and without dp it is O(2^n) and space complexity is O(n)
public:
    int dfs(string& s, int idx, vector<int>& dp){
        if(idx == s.length()) return 1;
        if(s[idx] == '0' ) return 0;
        if(dp[idx] != -1) return dp[idx];

        dp[idx] = dfs(s, idx+1, dp);
        if(idx + 1 < s.length() && (s[idx] == '1' || (s[idx] =='2' && s[idx+1] <= '6'))) dp[idx] += dfs(s, idx + 2, dp);
        return dp[idx];

    }
    int numDecodings(string s) {
        vector<int> dp (s.length(), -1);
        return dfs(s, 0, dp);
        
    }
};