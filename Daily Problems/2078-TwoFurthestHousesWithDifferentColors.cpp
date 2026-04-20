class Solution {
    // Here I have used greedy approach with TC O(n) and SC O(1)
public:
    int maxDistance(vector<int>& colors) {
        int left1 = 0, right1 = colors.size() -1;
        int left2 = 0, right2 = colors.size() -1;
        while(true){
            if(colors[left1] != colors[right1]) return right1-left1;
            if(colors[left2] != colors[right2]) return right2-left2;
            left1++;
            right2--;
        }
        return 0;
        
    }
};