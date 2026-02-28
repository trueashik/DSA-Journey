// Last updated: 2/1/2026, 6:51:05 PM
1class Solution {
2public:
3    int minCostConnectPoints(vector<vector<int>>& points) {
4        int n = points.size();
5        vector<bool>used(n, false);
6        vector<int>minDist(n, INT_MAX);
7        minDist[0] = 0;
8        int ans =0;
9
10        for(int i = 0; i < n; i++){
11            int tmp = -1;
12           
13            for(int v = 0; v < n; v++){
14                if(!used[v] && (tmp == -1 || minDist[tmp] > minDist[v])) tmp = v;
15            }
16            used[tmp] = true;
17            ans+=minDist[tmp];
18
19            for(int j = 0; j < n; j++){
20                int cost = abs(points[tmp][0]-points[j][0]) + abs(points[tmp][1]-points[j][1]);
21                if(!used[j])minDist[j] = min(minDist[j], cost);
22            }
23
24
25        }
26        return ans;
27        
28    }
29};