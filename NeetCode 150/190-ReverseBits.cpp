class Solution {
    // Here it is solved using Bit Manipulation with TC and SC O(1)
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)){
                res |= 1 << (31-i);
            }
        }
        return res;        
    }
};