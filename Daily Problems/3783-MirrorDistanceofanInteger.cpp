class Solution {
    // Here I have used reverse integer approach with TC O(n) and SC O(1)
public:
    int mirrorDistance(int n) {
        long long rev = 0;
        long long num = n;
        while(n){
            rev = (rev*10) + n%10;
            n/=10;
        }
        return abs(num - rev);
    }
};