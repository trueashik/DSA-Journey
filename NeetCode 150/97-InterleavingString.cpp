class Solution {
    // Here I have used recursion with memoization with TC O(n*m) and SC O(n*m)
public:
    bool memo(string& s1, string& s2, string& s3,int is1, int is2, vector<vector<int>>& dp){
        if(is1 == s1.size() && is2 == s2.size()) return true;
        if(dp[is1][is2] != -1) return dp[is1][is2];
        int idx = is1 + is2;
        bool ans = false;

        
        if(is1 < s1.size() && s1[is1] == s3[idx]){
            ans |= memo(s1, s2, s3, is1+1, is2, dp);
        }
        if(is2 < s2.size() && s2[is2] == s3[idx]){
            ans |= memo(s1, s2, s3, is1, is2+1, dp);          
        }
        

        return dp[is1][is2] = ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        if(s1.size() + s2.size() != s3.size()) return false;
        return memo(s1, s2, s3, 0, 0, dp);
        
    }
};
