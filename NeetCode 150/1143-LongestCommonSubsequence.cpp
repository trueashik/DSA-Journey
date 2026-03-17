class Solution {
    // Here I have used top to bottom DP approach with TC O(n*m) and SC O(n*m)
public:
    int DP(string&text1, string&text2, int x1, int x2, vector<vector<int>>&dp){
        int n1 = text1.size(), n2 = text2.size();
        if(x1 >= n1 || x2 >= n2) return 0;
        if(dp[x1][x2] != -1) return dp[x1][x2];
        if(text1[x1] == text2[x2]) return dp[x1][x2] = 1+DP(text1, text2, x1+1, x2+1, dp); 
        return dp[x1][x2] = max(DP(text1, text2, x1+1, x2, dp), DP(text1, text2, x1, x2+1, dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return DP(text1, text2, 0, 0, dp);
        
    }
};