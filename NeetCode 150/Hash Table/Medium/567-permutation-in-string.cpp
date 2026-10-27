// ═══════════════════════════════════════════════════════
// Problem: 567. Permutation in String
// Difficulty: Medium
// Topics: Hash Table, Two Pointers, String, Sliding Window
// Runtime: 0 ms (Beats 100.0%)
// Memory: 10.1 MB (Beats 44.2%)
// Submitted: Oct 27, 2026
// Link: https://leetcode.com/problems/permutation-in-string/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    bool isSame(vector<int> &freq, vector<int>&f){
        for(int i = 0; i < 26; i++){
            if(freq[i] != f[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int n = s2.size();
        int s = s1.size();
        if (s > n) return false;

        vector<int> freq (26, 0);
        for(char c : s1) {
            freq[c-'a']++;
        } 

        vector<int> f (26, 0);
        for(int i= l; i < s-1; i++) {
            f[s2[i]-'a']++;
        }

        for(int r = s-1; r<n ; r++){  
            
            f[s2[r]-'a']++;         
            if(isSame(freq, f)) return true;
            f[s2[l++]-'a']--;

        } 
        return false;     
    }
};
