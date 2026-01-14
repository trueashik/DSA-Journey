// Last updated: 1/14/2026, 6:38:50 PM
1class Solution {
2public:
3
4    int search(vector<vector<int>>& grid, int x, int y, int m, int n){
5        if(x < 0 || y < 0 || x >= m || y >= n) return 0;
6        if(grid[x][y] != 1) return 0;
7
8        grid[x][y] = -1;
9
10
11        return search(grid, x + 1, y, m, n) + search(grid, x - 1, y, m, n) + search(grid, x, y + 1, m, n) + search(grid, x, y - 1, m, n) + 1;
12    }
13    int maxAreaOfIsland(vector<vector<int>>& grid) {
14        int maxarea = 0;
15        int m = grid.size();
16        int n = grid[0].size();
17
18        for(int i = 0; i < m; i++){
19            for(int j = 0; j < n; j++){
20                if(grid[i][j] == 1){                   
21                    maxarea = max(maxarea, search(grid, i, j, m, n));
22                }
23            }
24        }
25        return maxarea;
26        
27    }
28};