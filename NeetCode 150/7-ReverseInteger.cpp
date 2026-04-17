class Solution {
     // Here I have used Math approach with TC and SC O(1)
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            int digit = x%10;

            if (res > INT_MAX/10 || (res == INT_MAX && digit > 7)) return 0;
            if (res < INT_MIN/10 || (res == INT_MIN && digit < -8)) return 0;

            res = (res*10) + digit;
            x /= 10;
        }  
        return res;      
    }
};