class Solution {
     // Here I have used simple iteration approach with TC O(n) and SC O(1)
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n -1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            } 
            digits[i] = 0;     
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};