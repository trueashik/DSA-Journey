// ═══════════════════════════════════════════════════════
// Problem: 155. Min Stack
// Difficulty: Medium
// Topics: Stack, Design
// Runtime: 217 ms (Beats 7.2%)
// Memory: 151.1 MB (Beats 79.9%)
// Submitted: Oct 29, 2026
// Link: https://leetcode.com/problems/min-stack/
// ═══════════════════════════════════════════════════════

class MinStack {
public:
    stack<int> st;
    stack<int> stmin;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if (stmin.empty() || stmin.top() >= value){
            stmin.push(value);
        }
    }
    
    void pop() {
       if (st.top() == stmin.top()) stmin.pop();
       st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return stmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
