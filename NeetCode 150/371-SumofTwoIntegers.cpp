class Solution {
    // Here it is solved using Bit Manipulation with TC and SC O(1)
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i = 0; i < 32 && (a || b || carry); i++){
            int abit = a & 1;
            int bbit = b & 1;
            if(abit && bbit){
                if(carry){
                    res |= 1 << i;
                }else{
                    carry = 1;
                }
            }else if(abit || bbit){
                if(!carry){
                    res |= 1 << i;
                }
            }else {
                if(carry){
                    res |= 1<<i;
                    carry = 0;
                }
            }
            a >>= 1;
            b >>= 1;
        }
        return res;
        
    }
};