class Solution {
    // Here I have used greedy approach with TC O(n) and SC O(1)
public:
    int furthestDistanceFromOrigin(string moves) {
        int Lm =0, Rm = 0, gap = 0;;
        for(char c : moves){
            if(c == 'L'){
                Lm++;
            }else if (c == 'R'){
                Rm++;
            }else gap++;
        }
        return abs(Lm - Rm) + gap;
        
    }
};