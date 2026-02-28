// Last updated: 1/20/2026, 1:05:32 PM
1class Solution {
2public:
3    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
4        vector<vector<int>> ans;
5        unordered_set<long long> p, a, v;
6        int m = heights.size(), n = heights[0].size();
7        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
8
9        auto key = [&](int x, int y) {
10            return ((long long)x << 32) | (unsigned int)y;
11        };
12
13        queue<pair<int,int>> q;
14
15        // -------- Pacific --------
16        for (int i = 0; i < m; i++) {
17            q.push({i,0});
18            v.insert(key(i,0));
19            p.insert(key(i,0));        // 🔴 FIX
20        }
21        for (int j = 0; j < n; j++) {
22            q.push({0,j});
23            v.insert(key(0,j));
24            p.insert(key(0,j));        // 🔴 FIX
25        }
26
27        while (!q.empty()) {
28            auto [x,y] = q.front(); q.pop();
29            for (auto &d : dir) {
30                int nx = x + d[0], ny = y + d[1];
31                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
32                if (heights[nx][ny] < heights[x][y]) continue;
33
34                long long k = key(nx,ny);
35                if (!v.insert(k).second) continue;
36
37                p.insert(k);
38                q.push({nx,ny});
39            }
40        }
41
42        // -------- Atlantic --------
43        v.clear();
44        q = queue<pair<int,int>>();
45
46        for (int i = 0; i < m; i++) {
47            q.push({i,n-1});
48            v.insert(key(i,n-1));
49            a.insert(key(i,n-1));      // 🔴 FIX
50        }
51        for (int j = 0; j < n; j++) {
52            q.push({m-1,j});
53            v.insert(key(m-1,j));
54            a.insert(key(m-1,j));      // 🔴 FIX
55        }
56
57        while (!q.empty()) {
58            auto [x,y] = q.front(); q.pop();
59            for (auto &d : dir) {
60                int nx = x + d[0], ny = y + d[1];
61                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
62                if (heights[nx][ny] < heights[x][y]) continue;
63
64                long long k = key(nx,ny);
65                if (!v.insert(k).second) continue;
66
67                a.insert(k);
68                q.push({nx,ny});
69            }
70        }
71
72        // -------- Intersection --------
73        for (auto &k : p) {
74            if (a.count(k)) {
75                int x = k >> 32;
76                int y = (int)(k & 0xffffffff);
77                ans.push_back({x,y});
78            }
79        }
80
81        return ans;
82    }
83};
84