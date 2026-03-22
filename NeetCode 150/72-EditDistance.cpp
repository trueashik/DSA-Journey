class Solution {
    // Here I have used recursion with memoization with TC O(n*m) and SC O(n*m)
public:
    int memo(string& word1, string& word2, int x, int y, vector<vector<int>>& dp){
        if(dp[x][y] != -1) return dp[x][y];
        int s1 = word1.size();
        int s2 = word2.size();
        
        if(x == s1) return s2 - y;
        if(y == s2) return s1 - x;

        if(word1[x] == word2[y]){
            return dp[x][y] = memo(word1, word2, x+1, y+1, dp);            
        }
        int replaceOp = memo(word1, word2, x+1, y+1, dp);
        int insertOp = memo(word1, word2, x, y+1, dp);
        int deleteOp = memo(word1, word2, x+1, y, dp);

  
        return dp[x][y] = 1 + min({replaceOp, insertOp, deleteOp});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() +1, vector<int>(word2.size()+1, -1));
        return memo(word1, word2, 0, 0, dp);
        
    }
};