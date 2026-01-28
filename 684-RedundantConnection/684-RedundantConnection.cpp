// Last updated: 1/28/2026, 10:18:38 PM
1class Solution {
2public:
3    vector<int>parent, rank;
4    int find(int x){
5        if(parent[x] != x){
6            parent[x] = find(parent[x]);
7        }
8        return parent[x];
9    }
10    bool Union(int x, int y){
11        int px = find(x);
12        int py = find(y);
13        if(px == py){
14            return false;
15        }
16        if(rank[px] >= rank[py]){
17            parent[py] = parent[px];
18        }else{
19            parent[px] = parent[py];
20            rank[py]++;
21        }
22        return true;
23
24    }
25    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
26        parent.resize(edges.size()+1);
27        rank.assign(edges.size()+1, 0);
28        int idx = 0;
29        for(int i = 1; i <= edges.size(); i++){
30            parent[i] = i;          
31        }
32        for(int i = 0; i < edges.size(); i++){
33            if(!Union(edges[i][0], edges[i][1])){
34                idx = i;
35            }
36
37        }
38        return edges[idx];
39        
40    }
41};