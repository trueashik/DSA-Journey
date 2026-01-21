// Last updated: 1/21/2026, 7:08:17 PM
1class Solution {
2public:
3// Uses recursion with TC and SC O(m*n);
4
5    void dfs(vector<vector<char>>& board, int x, int y){
6        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;
7        if(board[x][y] != 'O'){
8            return;
9        } else board[x][y] = 'Z';
10        dfs(board, x, y+1);
11        dfs(board, x, y-1);
12        dfs(board, x+1, y);
13        dfs(board, x-1, y);
14    }
15    void solve(vector<vector<char>>& board) {
16        if(board.empty() || board[0].empty()) return;
17        int m = board.size();
18        int n = board[0].size();
19
20        for(int i = 0; i < m; i++){
21            if(board[i][0] == 'O') dfs(board, i, 0);
22            if(board[i][n-1] == 'O') dfs(board, i, n-1);
23        }
24        for(int i = 0; i < n; i++){
25            if(board[0][i] == 'O') dfs(board, 0, i);
26            if(board[m-1][i] == 'O') dfs(board, m-1, i);
27        }
28
29        for(int i = 0; i < m ; i++){
30            for(int j = 0; j < n; j++){
31                board[i][j] = board[i][j] == 'O' ? 'X' : board[i][j] == 'Z' ? 'O' : board[i][j];
32            }
33        }
34        
35    }
36};