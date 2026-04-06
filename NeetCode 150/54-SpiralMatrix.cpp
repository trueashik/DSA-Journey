class Solution {
    // Here I have used two pointer approach with TC O(n*m) and SC O(1)
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;

        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (!(left <= right && top <= bottom)) {
                break;
            }
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i = bottom; i >=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
        
    }
};