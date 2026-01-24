// Last updated: 1/24/2026, 1:29:42 PM
1class Solution {
2public:
3    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>> nums(numCourses);
5        vector<int> indegree(numCourses, 0);
6        vector<int>res;
7        
8        for(int i = 0; i < prerequisites.size(); i++){
9            indegree[prerequisites[i][0]]++;
10            nums[prerequisites[i][1]].push_back(prerequisites[i][0]);
11        }
12        queue<int>q;
13        for(int i = 0; i < indegree.size(); i++){
14            if(indegree[i]==0)q.push(i);
15        }
16        while(!q.empty()){
17            for(int i : nums[q.front()]){
18                indegree[i]--;
19                if(indegree[i] == 0) q.push(i);
20            }
21            res.push_back(q.front());
22            q.pop();
23
24        }
25        if(res.size() == numCourses){
26            return res;
27        }
28        return {};
29    }
30};