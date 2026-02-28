// Last updated: 12/28/2025, 12:25:59 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4
5        // Here i used two pointers sliding window of TC O(n) & O(k) SC
6        int maxx=0;
7        int l = 0;
8        unordered_set<int> mp;
9
10        for(int r = 0; r < s.size(); r++){
11
12            while(mp.find(s[r]) != mp.end()){
13                mp.erase(s[l]);
14                l++;
15                
16            }
17            maxx = max(r-l+1, maxx);
18            mp.insert(s[r]);
19        }
20
21
22        return maxx;
23        
24    }
25};