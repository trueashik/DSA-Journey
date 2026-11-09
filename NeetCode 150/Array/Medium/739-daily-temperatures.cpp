// ═══════════════════════════════════════════════════════
// Problem: 739. Daily Temperatures
// Difficulty: Medium
// Topics: Array, Stack, Monotonic Stack
// Runtime: 48 ms (Beats 5.1%)
// Memory: 112 MB (Beats 5.8%)
// Submitted: Nov 9, 2026
// Link: https://leetcode.com/problems/daily-temperatures/
// ═══════════════════════════════════════════════════════


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<pair<int, int>> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && temperatures[i] > st.top().first) {
                int idx = st.top().second;
                ans[idx] = i - idx;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return ans;
    }
};

