class Solution {
    // Here I have used transpose and reverse approach with TC O(n^2) and SC O(1)
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