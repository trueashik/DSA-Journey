// Last updated: 1/14/2026, 6:11:55 PM
1class Solution {
2public:
3
4    void search(vector<vector<char>>& grid, int x, int y, int m, int n){
5        if(x < 0 || y < 0 || x >= m || y >= n) return;
6        if(grid[x][y] != '1') return;
7
8        
9        grid[x][y] = '2';
10        search(grid, x, y+1, m, n);
11        search(grid, x, y-1, m, n);
12        search(grid, x+1, y, m, n);
13        search(grid, x-1, y, m, n);
14    }
15
16    int numIslands(vector<vector<char>>& grid) {
17        int res = 0;
18        int m = grid.size();
19        int n = grid[0].size();
20        for(int i = 0; i < m; i++){
21            for(int j = 0; j < n; j++){
22                if(grid[i][j] == '1'){
23                    search(grid, i, j, m, n);
24                    res++;
25                }
26            }
27        }  
28        return res;       
29        
30    }
31};