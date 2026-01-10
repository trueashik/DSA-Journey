// Last updated: 1/10/2026, 10:14:04 PM
1class Trie {
2    // Here used trie with tc & SC O(L);
3public:
4    struct Node {
5        Node* next[26] = {};
6        bool isend = false;
7    };
8    
9    Node* root;
10    Trie() {
11        root = new Node();
12        
13    }
14    
15    void insert(string word) {  
16        Node* cur = root;    
17        for(int i = 0; i < word.length(); i++){
18            int idx = word[i] - 'a';
19
20            if(!cur->next[idx]){
21                cur->next[idx] = new Node();
22            }
23            cur = cur->next[idx];
24
25        }
26        cur->isend = true;
27        
28    }
29    
30    bool search(string word) {
31        Node* cur = root;    
32        for(int i = 0; i < word.length(); i++){
33            int idx = word[i] - 'a';
34
35            if(cur->next[idx] == nullptr) return false;
36            cur = cur->next[idx];
37
38        }
39        if(cur->isend) return true;
40        return false;
41        
42    }
43    
44    bool startsWith(string prefix) {
45        Node* cur = root;    
46        for(int i = 0; i < prefix.length(); i++){
47            int idx = prefix[i] - 'a';
48
49            if(cur->next[idx] == nullptr) return false;
50            cur = cur->next[idx];
51
52        }
53        return true;
54        
55    }
56};
57
58/**
59 * Your Trie object will be instantiated and called as such:
60 * Trie* obj = new Trie();
61 * obj->insert(word);
62 * bool param_2 = obj->search(word);
63 * bool param_3 = obj->startsWith(prefix);
64 */