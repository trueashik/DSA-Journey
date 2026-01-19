// Last updated: 1/19/2026, 11:12:29 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        queue<pair<int, int>>q;
5        int ans = 0;
6        int fresh = 0;
7        int m = grid.size();
8        int n = grid[0].size();
9        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
10
11        for(int i = 0; i < m; i++){
12            for(int j = 0; j < n; j++){
13                if(grid[i][j] == 2) q.push({i, j});
14                if(grid[i][j] == 1) fresh++;
15            }
16        }
17        
18
19        while(!q.empty() && fresh > 0){
20            int sz = q.size();
21            ans++;
22            
23            while(sz--){
24                auto [x, y] = q.front();
25                q.pop();
26
27                
28                for(int i = 0; i < 4; i++){
29                    int dx = x + dir[i][0];
30                    int dy = y + dir[i][1];
31                    if(dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
32                    if(grid[dx][dy] == 1){
33                        grid[dx][dy] = 2;
34                        q.push({dx, dy});
35                        fresh--;
36                    } 
37                    
38                }
39
40            }
41        }
42        return fresh == 0? ans : -1;
43        
44    }
45};