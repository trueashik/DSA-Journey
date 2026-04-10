class Solution {
    // Here I have used binary exponentiation approach with TC O(log n) and SC O(1)
public: 
    double myPow(double x, int n) {
        long long num = n;
        if(num < 0){
            num = -num;
            x = 1/x;
        }
        if (n == 0) return 1;
        double res = 1;
        while(num > 0){
            if(num % 2 == 1){
                res*=x;
            }
            x *= x;
            num /= 2;
        }
        return res;  
    }
};