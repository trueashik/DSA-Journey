// Last updated: 1/1/2026, 5:05:52 PM
1class Solution {
2public:
3    bool ispd(string& s, int left, int right){
4        while(left < right){
5            if(s[left++] != s[right--]) return false;            
6        }
7        return true;
8    }
9
10    void backtrack(string& s, vector<vector<string>>& res, vector<string>& root, int l){
11        if (l == s.length()){
12            res.push_back(root);
13            return;
14        }
15        string draft;
16        for(int i = l; i < s.length(); i++){
17            draft+=s[i];
18            if(ispd(s, l, i)){
19                root.push_back(draft);
20                backtrack(s, res, root, i + 1);
21                root.pop_back();
22            }
23        }
24    }
25    vector<vector<string>> partition(string s) {
26        vector<vector<string>> res;
27        vector<string> root;
28        backtrack(s, res, root, 0);
29        return res;
30        
31    }
32};