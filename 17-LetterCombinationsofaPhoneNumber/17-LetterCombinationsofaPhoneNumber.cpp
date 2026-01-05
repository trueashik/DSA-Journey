// Last updated: 1/5/2026, 4:50:38 PM
1class Solution {
2public:
3
4    void backtrack(string& digits,unordered_map<int, string>& mp, vector<string>& res, string& draft, int idx){
5        if(idx == digits.length()){
6            res.push_back(draft);
7            return;
8        }
9        int num = digits[idx] - '0';
10        for(int i = 0; i < mp[num].length(); i++){
11            draft += mp[num][i];
12            backtrack(digits, mp, res, draft, idx + 1);
13            draft.pop_back();
14        }
15    }
16    vector<string> letterCombinations(string digits) {
17        if(digits.empty()) return {};
18        unordered_map<int, string> mp = {
19            {2, "abc"},
20            {3, "def"},
21            {4, "ghi"},
22            {5, "jkl"},
23            {6, "mno"},
24            {7, "pqrs"},
25            {8, "tuv"},
26            {9, "wxyz"}
27        };
28        string draft;
29        vector<string> res;
30        backtrack(digits, mp, res, draft, 0);
31
32        return res;
33
34        
35    }
36};