// Last updated: 1/17/2026, 11:45:39 AM
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
26        auto it = mp.insert({n, 0});
27        if(it.second){
28            Node* tmp = new Node(n->val);
29            mp[n] = tmp;
30            recurse(n, tmp, mp);
31        }
32        ans->neighbors.push_back(mp[n]);
33        
34        
35    }
36}
37
38class Solution {
39public:
40    Node* cloneGraph(Node* node) { 
41        if (!node) return nullptr;       
42        unordered_map<Node*, Node*> mp;
43
44        Node* ans = new Node(node->val);
45        mp[node] = ans;
46        recurse(node, ans, mp);
47        return ans;
48        
49    }
50};