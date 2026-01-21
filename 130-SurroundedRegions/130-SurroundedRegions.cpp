// Last updated: 1/21/2026, 6:56:26 PM
1class Solution {
2public:
3
4    void dfs(vector<vector<char>>& board, int x, int y){
5        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;
6        if(board[x][y] != 'O'){
7            return;
8        } else board[x][y] = 'Z';
9        dfs(board, x, y+1);
10        dfs(board, x, y-1);
11        dfs(board, x+1, y);
12        dfs(board, x-1, y);
13    }
14    void solve(vector<vector<char>>& board) {
15        int m = board.size();
16        int n = board[0].size();
17
18        for(int i = 0; i < m; i++){
19            if(board[i][0] == 'O') dfs(board, i, 0);
20            if(board[i][n-1] == 'O') dfs(board, i, n-1);
21        }
22        for(int i = 0; i < n; i++){
23            if(board[0][i] == 'O') dfs(board, 0, i);
24            if(board[m-1][i] == 'O') dfs(board, m-1, i);
25        }
26
27        for(int i = 0; i < m ; i++){
28            for(int j = 0; j < n; j++){
29                board[i][j] = board[i][j] == 'O' ? 'X' : board[i][j] == 'Z' ? 'O' : board[i][j];
30            }
31        }
32        
33    }
34};