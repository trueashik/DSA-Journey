// Last updated: 1/14/2026, 6:24:36 PM
1class Solution {
2public:
3    
4    // I did it by recursion with O(m*n) TC & SC;
5
6    void search(vector<vector<char>>& grid, int x, int y, int m, int n){
7        if(x < 0 || y < 0 || x >= m || y >= n) return;
8        if(grid[x][y] != '1') return;
9
10        
11        grid[x][y] = '2';
12        search(grid, x, y+1, m, n);
13        search(grid, x, y-1, m, n);
14        search(grid, x+1, y, m, n);
15        search(grid, x-1, y, m, n);
16    }
17
18    int numIslands(vector<vector<char>>& grid) {
19        int res = 0;
20        int m = grid.size();
21        int n = grid[0].size();
22        for(int i = 0; i < m; i++){
23            for(int j = 0; j < n; j++){
24                if(grid[i][j] == '1'){
25                    search(grid, i, j, m, n);
26                    res++;
27                }
28            }
29        }  
30        return res;       
31        
32    }
33};