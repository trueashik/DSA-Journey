// ═══════════════════════════════════════════════════════
// Problem: 20. Valid Parentheses
// Difficulty: Easy
// Topics: String, Stack, Bracket Sequences
// Runtime: 0 ms (Beats 100.0%)
// Memory: 8.9 MB (Beats 61.6%)
// Submitted: Oct 28, 2026
// Link: https://leetcode.com/problems/valid-parentheses/
// ═══════════════════════════════════════════════════════


class Solution {
public:
    bool isValid(string s) {
        stack<char> fq;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                fq.push(ch);
            } 
            else {
                if (fq.empty()) return false;

                if ((ch == ')' && fq.top() == '(') ||
                    (ch == '}' && fq.top() == '{') ||
                    (ch == ']' && fq.top() == '[')) {
                    fq.pop();
                } 
                else {
                    return false;
                }
            }
        }

        return fq.empty();
    }
};

