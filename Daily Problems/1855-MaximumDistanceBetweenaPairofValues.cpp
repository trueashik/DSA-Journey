class Solution {
    // Here I have used two pointer approach with TC O(n) and SC O(1)
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0;
        int l2 = 0;
        int res = 0;

        while(l2 < nums2.size() && l1 < nums1.size()){
            
            if(nums1[l1] <= nums2[l2]){
                res = max(res, l2-l1);
                l2++;
            }else l1++;
        }
        return res;
        
    }
};