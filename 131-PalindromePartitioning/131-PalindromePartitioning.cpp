// Last updated: 1/1/2026, 5:10:19 PM
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
15        for(int i = l; i < s.length(); i++){
16            if(ispd(s, l, i)){
17                root.push_back(s.substr(l, i - l + 1));
18                backtrack(s, res, root, i + 1);
19                root.pop_back();
20            }
21        }
22    }
23    vector<vector<string>> partition(string s) {
24        vector<vector<string>> res;
25        vector<string> root;
26        backtrack(s, res, root, 0);
27        return res;
28        
29    }
30};