// ═══════════════════════════════════════════════════════
// Problem: 48. Rotate Image
// Difficulty: Medium
// Topics: Array, Math, Matrix
// Runtime: 0 ms (Beats 100.0%)
// Memory: 10.2 MB (Beats 68.5%)
// Submitted: May 4, 2026
// Link: https://leetcode.com/problems/rotate-image/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[0].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};
