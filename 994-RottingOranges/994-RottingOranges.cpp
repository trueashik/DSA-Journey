// Last updated: 1/28/2026, 10:12:26 PM
1class Solution {
2    // Here it is done by BFS level with TC and SC O(m*n)
3public:
4    int orangesRotting(vector<vector<int>>& grid) {
5        queue<pair<int, int>>q;
6        int ans = 0;
7        int fresh = 0;
8        int m = grid.size();
9        int n = grid[0].size();
10        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
11
12        for(int i = 0; i < m; i++){
13            for(int j = 0; j < n; j++){
14                if(grid[i][j] == 2) q.push({i, j});
15                if(grid[i][j] == 1) fresh++;
16            }
17        }
18        
19
20        while(!q.empty() && fresh > 0){
21            int sz = q.size();
22            ans++;
23            
24            while(sz--){
25                auto [x, y] = q.front();
26                q.pop();
27
28                
29                for(int i = 0; i < 4; i++){
30                    int dx = x + dir[i][0];
31                    int dy = y + dir[i][1];
32                    if(dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
33                    if(grid[dx][dy] == 1){
34                        grid[dx][dy] = 2;
35                        q.push({dx, dy});
36                        fresh--;
37                    } 
38                    
39                }
40
41            }
42        }
43        return fresh == 0? ans : -1;
44        
45    }
46};