// Last updated: 1/26/2026, 5:37:00 PM
1class Solution {
2public:
3    
4
5    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
6        vector<vector<int>>nums(numCourses);
7        vector<int>indegree(numCourses, 0);
8        int completed = 0;
9        queue<int> q;
10
11
12        for(int i = 0; i < prerequisites.size(); i++){
13            indegree[prerequisites[i][0]]++;
14            nums[prerequisites[i][1]].push_back(prerequisites[i][0]) ;
15        }
16        for(int i = 0; i < indegree.size(); i++){
17            if(indegree[i] == 0) q.push(i);
18        }
19
20        while(!q.empty()){
21            
22            for(int i : nums[q.front()]){
23                indegree[i]--;
24                if(!indegree[i])q.push(i);
25            }
26            q.pop();
27            completed++;
28        }
29
30        return completed == numCourses;
31        
32    }
33};