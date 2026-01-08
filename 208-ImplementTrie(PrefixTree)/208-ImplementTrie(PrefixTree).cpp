// Last updated: 1/8/2026, 10:05:09 PM
1class Trie {
2public:
3    struct Node {
4        Node* next[26] = {};
5        bool isend = false;
6    };
7    
8    Node* root;
9    Trie() {
10        root = new Node();
11        
12    }
13    
14    void insert(string word) {  
15        Node* cur = root;    
16        for(int i = 0; i < word.length(); i++){
17            int idx = word[i] - 'a';
18
19            if(!cur->next[idx]){
20                cur->next[idx] = new Node();
21            }
22            cur = cur->next[idx];
23
24        }
25        cur->isend = true;
26        
27    }
28    
29    bool search(string word) {
30        Node* cur = root;    
31        for(int i = 0; i < word.length(); i++){
32            int idx = word[i] - 'a';
33
34            if(cur->next[idx] == nullptr) return false;
35            cur = cur->next[idx];
36
37        }
38        if(cur->isend) return true;
39        return false;
40        
41    }
42    
43    bool startsWith(string prefix) {
44        Node* cur = root;    
45        for(int i = 0; i < prefix.length(); i++){
46            int idx = prefix[i] - 'a';
47
48            if(cur->next[idx] == nullptr) return false;
49            cur = cur->next[idx];
50
51        }
52        return true;
53        
54    }
55};
56
57/**
58 * Your Trie object will be instantiated and called as such:
59 * Trie* obj = new Trie();
60 * obj->insert(word);
61 * bool param_2 = obj->search(word);
62 * bool param_3 = obj->startsWith(prefix);
63 */