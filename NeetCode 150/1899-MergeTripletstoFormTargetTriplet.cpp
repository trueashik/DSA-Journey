class Solution {
    // Here I have used greedy approach with TC O(n) and SC O(1)
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;
        for(auto& triple : triplets){
            if(target[0] >= triple[0] && target[1] >= triple[1] && target[2] >= triple[2]){
                x |= (target[0] == triple[0]);
                y |= (target[1] == triple[1]);
                z |= (target[2] == triple[2]);                
            }
        }
        return (x && y && z);
        
    }
};