// Last updated: 1/17/2026, 11:47:21 AM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21void recurse(Node* node, Node* ans, unordered_map<Node*, Node*>& mp){
22    if(!node) return;
23
24    for(Node* n : node->neighbors){
25
26        if(!mp.count(n)){
27            Node* tmp = new Node(n->val);
28            mp[n] = tmp;
29            recurse(n, tmp, mp);
30        }
31        ans->neighbors.push_back(mp[n]);
32        
33        
34    }
35}
36
37class Solution {
38public:
39    Node* cloneGraph(Node* node) { 
40        if (!node) return nullptr;       
41        unordered_map<Node*, Node*> mp;
42
43        Node* ans = new Node(node->val);
44        mp[node] = ans;
45        recurse(node, ans, mp);
46        return ans;
47        
48    }
49};