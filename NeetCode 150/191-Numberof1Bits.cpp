class Solution {
    // Here it is solved using Bit Manipulation with TC and SC O(1) 
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n){
            if((n | 1) == n) res++;
            n >>= 1;
        }
        return res;
    }
};