// Last updated: 12/31/2025, 8:35:31 PM
1class Solution {
2public:
3    void backtrack(vector<vector<char>>& board, string& word, bool& res, int r, int c, int idx ){
4        if(res) return;
5        if(idx == word.size()){
6            res = true;
7            return;
8        }
9        if(r >= board.size() || r < 0 || c >= board[0].size() || c < 0 || board[r][c] == '#') return;
10
11        if(board[r][c] == word[idx]){
12            char tmp = board[r][c];
13            board[r][c] = '#';
14 
15
16            backtrack(board, word, res, r+1, c, idx + 1);
17            backtrack(board, word, res, r-1, c, idx + 1);
18            backtrack(board, word, res, r, c+1, idx + 1);
19            backtrack(board, word, res, r, c-1, idx + 1);
20            board[r][c] = tmp;
21
22        }
23        
24    }
25
26
27    bool exist(vector<vector<char>>& board, string word) {
28        bool res = false;
29
30        for(int i = 0; i < board.size(); i++){
31            for(int j = 0; j < board[i].size(); j++){
32                if(board[i][j] == word[0]) {
33                    backtrack(board, word, res, i, j, 0);
34                }
35                if(res) break;
36            }
37            if(res) break;
38        }
39        return res;
40       
41    }
42};