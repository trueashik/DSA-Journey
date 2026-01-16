// Last updated: 1/16/2026, 11:40:29 PM
1class Solution {
2public:
3    // Here I did recursion with TC & SC O(m*n) 
4
5    int search(vector<vector<int>>& grid, int x, int y, int m, int n){
6        if(x < 0 || y < 0 || x >= m || y >= n) return 0;
7        if(grid[x][y] != 1) return 0;
8
9        grid[x][y] = -1;
10
11
12        return search(grid, x + 1, y, m, n) + search(grid, x - 1, y, m, n) + search(grid, x, y + 1, m, n) + search(grid, x, y - 1, m, n) + 1;
13    }
14    int maxAreaOfIsland(vector<vector<int>>& grid) {
15        int maxarea = 0;
16        int m = grid.size();
17        int n = grid[0].size();
18
19        for(int i = 0; i < m; i++){
20            for(int j = 0; j < n; j++){
21                if(grid[i][j] == 1){                   
22                    maxarea = max(maxarea, search(grid, i, j, m, n));
23                }
24            }
25        }
26        return maxarea;
27        
28    }
29};