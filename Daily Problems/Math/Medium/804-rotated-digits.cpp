// ═══════════════════════════════════════════════════════
// Problem: 804. Rotated Digits
// Difficulty: Medium
// Topics: Math, Dynamic Programming
// Runtime: 0 ms (Beats 100.0%)
// Memory: 8 MB (Beats 46.7%)
// Submitted: May 2, 2026
// Link: https://leetcode.com/problems/rotated-digits/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int rotatedDigits(int n) {
        
        int res = 0;
        for(int i = 1; i <= n; i++){
            int x = i;
            bool valid = true;
            bool diff = false;
            while(x){
                int d =  x%10;
                if(d == 3 || d == 4 || d == 7){
                    valid = false;
                    break;
                }
                if(d == 2 || d == 5 || d == 6 || d == 9){
                    diff = true;
                }
                x/=10;
            }
            if(valid && diff) res++;
        }
        return res;
        
    }
};
