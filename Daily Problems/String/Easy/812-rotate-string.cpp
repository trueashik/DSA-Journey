// ═══════════════════════════════════════════════════════
// Problem: 812. Rotate String
// Difficulty: Easy
// Topics: String, String Matching
// Runtime: 2 ms (Beats 12.5%)
// Memory: 8.2 MB (Beats 36.3%)
// Submitted: May 4, 2026
// Link: https://leetcode.com/problems/rotate-string/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if (s.length() != goal.length()) return false;
        return (s + s).find(goal) != string::npos;
    }
};
