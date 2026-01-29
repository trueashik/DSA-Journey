// Last updated: 1/29/2026, 9:52:48 PM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<vector<pair<int, int>>>adj(n+1);
5        vector<int>dist(n+1, INT_MAX);
6        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
7        int ans = 0;
8
9        for(auto &t : times){
10            adj[t[0]].push_back({t[2], t[1]});
11        }
12        dist[k] = 0;
13        pq.push({0, k});
14
15        while(!pq.empty()){
16            auto [time, node] = pq.top();
17            pq.pop();
18            if(dist[node] < time) continue;
19            
20
21            for(auto [t, n]: adj[node]){
22                if(dist[n]> t+time){
23                    dist[n] = t+time;
24                    pq.push({dist[n], n});
25                }
26
27            }
28        }
29        for(int d = 1; d < dist.size(); d++){
30            if(dist[d] == INT_MAX ) return -1;
31            ans = max(ans, dist[d]);
32        }
33        return ans;
34        
35    }
36};