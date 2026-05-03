// ═══════════════════════════════════════════════════════
// Problem: 812. Rotate String
// Difficulty: Easy
// Topics: String, String Matching
// Runtime: 0 ms (Beats 100.0%)
// Memory: 8 MB (Beats 84.8%)
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
