class Solution {
    // Here I have used Floyd's cycle detection algorithm with TC O(log n) and SC O(1)
public:
    int square(int n){
        int ans = 0;
        while(n){
            int tmp = n%10;
            ans+= tmp* tmp;
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = square(n);
        while(slow != fast){
            slow = square(slow);
            fast = square(square(fast));
        }
        return slow == 1;

        
    }
};