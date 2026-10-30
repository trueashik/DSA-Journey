// ═══════════════════════════════════════════════════════
// Problem: 150. Evaluate Reverse Polish Notation
// Difficulty: Medium
// Topics: Array, Math, Stack
// Runtime: 3 ms (Beats 33.9%)
// Memory: 17 MB (Beats 87.5%)
// Submitted: Oct 30, 2026
// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>ops;
        for(int i = 0; i < tokens.size(); i++){
            string c = tokens[i];
            if(c == "+"){
                int i2 = ops.top();
                ops.pop();
                int i1 = ops.top();
                ops.pop();
                ops.push(i1+i2);
            }else if(c == "-"){
                int i2 = ops.top();
                ops.pop();
                int i1 = ops.top();
                ops.pop();
                ops.push(i1-i2);
            }else if(c == "*"){
                int i2 = ops.top();
                ops.pop();
                int i1 = ops.top();
                ops.pop();
                ops.push(i1*i2);
            }else if(c == "/"){
                int i2 = ops.top();
                ops.pop();
                int i1 = ops.top();
                ops.pop();
                ops.push(i1/i2);
            } else {
                ops.push(stoi(c));
            }
        }
        return ops.top();
        
    }
};
