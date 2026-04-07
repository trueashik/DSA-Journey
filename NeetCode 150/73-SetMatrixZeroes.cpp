class Solution {
    // Here I have used two variables approach with TC O(n*m) and SC O(1)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool zeroROW = false, zeroCOL = false;
        for(int j = 0; j < m; j++){
                if(matrix[0][j] == 0){
                    zeroROW = true;
                    break;
                }
        }
        for(int i = 0; i < n; i++){
                if(matrix[i][0] == 0){
                    zeroCOL = true;
                    break;
                }
        }

        for(int i = 1 ;i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < n; i ++){
            if(matrix[i][0] == 0){
                for(int j = 0; j < m; j++){
                    matrix[i][j] = 0;
                }
            }
            
        }
        for(int j = 1; j < m; j++){
            if(matrix[0][j] == 0){
                for(int i = 0; i < n; i++){
                    matrix[i][j] = 0;
                }
            }
            
        }
        if(zeroROW){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        if(zeroCOL){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }

        
    }
};