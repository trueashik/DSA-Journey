// Last updated: 1/5/2026, 4:57:39 PM
1class Solution {
2public:
3
4    void backtrack(string& digits,vector<string>& mp, vector<string>& res, string& draft, int idx){
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
18        vector<string> db = {
19            {""},
20            {""},
21            {"abc"},
22            {"def"},
23            {"ghi"},
24            {"jkl"},
25            {"mno"},
26            {"pqrs"},
27            {"tuv"},
28            {"wxyz"}
29        };
30        string draft;
31        vector<string> res;
32        backtrack(digits, db, res, draft, 0);
33
34        return res;
35
36        
37    }
38};