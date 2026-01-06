// Last updated: 1/6/2026, 10:56:26 PM
1class Solution {
2     // Here i am using backtracking with TC O(4^n) and SC O(n);
3public:
4
5    void backtrack(string& digits,vector<string>& mp, vector<string>& res, string& draft, int idx){
6        if(idx == digits.length()){
7            res.push_back(draft);
8            return;
9        }
10        int num = digits[idx] - '0';
11        for(int i = 0; i < mp[num].length(); i++){
12            draft += mp[num][i];
13            backtrack(digits, mp, res, draft, idx + 1);
14            draft.pop_back();
15        }
16    }
17    vector<string> letterCombinations(string digits) {
18        if(digits.empty()) return {};
19        vector<string> db = {
20            "",
21            "",
22            "abc",
23            "def",
24            "ghi",
25            "jkl",
26            "mno",
27            "pqrs",
28            "tuv",
29            "wxyz"
30        };
31        string draft;
32        vector<string> res;
33        backtrack(digits, db, res, draft, 0);
34
35        return res;
36
37        
38    }
39};