// ═══════════════════════════════════════════════════════
// Problem: 424. Longest Repeating Character Replacement
// Difficulty: Medium
// Topics: Hash Table, String, Sliding Window
// Runtime: 2 ms (Beats 70.4%)
// Memory: 10.7 MB (Beats 98.7%)
// Submitted: Oct 25, 2026
// Link: https://leetcode.com/problems/longest-repeating-character-replacement/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int l = 0;
        int f[26] = {0};
        int maxf = 0;
        int ans = 0;

        for(int r = l; r < n; r++){
            f[s[r]-'A']++;
            maxf=max(maxf,f[s[r]-'A']);
            if(r-l+1 - maxf > k){
                f[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
        
    }
};
