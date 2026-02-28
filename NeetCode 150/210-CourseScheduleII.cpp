// Last updated: 1/24/2026, 1:34:54 PM
1class Solution {
2    // Here i have done it with Kahn's Algorithm with sc and tc as O(V+E)
3public:
4    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
5        vector<vector<int>> nums(numCourses);
6        vector<int> indegree(numCourses, 0);
7        vector<int>res;
8        
9        for(int i = 0; i < prerequisites.size(); i++){
10            indegree[prerequisites[i][0]]++;
11            nums[prerequisites[i][1]].push_back(prerequisites[i][0]);
12        }
13        queue<int>q;
14        for(int i = 0; i < indegree.size(); i++){
15            if(indegree[i]==0)q.push(i);
16        }
17        while(!q.empty()){
18            for(int i : nums[q.front()]){
19                indegree[i]--;
20                if(indegree[i] == 0) q.push(i);
21            }
22            res.push_back(q.front());
23            q.pop();
24
25        }
26        if(res.size() == numCourses){
27            return res;
28        }
29        return {};
30    }
31};