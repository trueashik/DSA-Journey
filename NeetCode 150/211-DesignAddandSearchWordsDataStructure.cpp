// Last updated: 1/13/2026, 9:13:41 PM
1class WordDictionary {
2    // Here i have added a trie with TC O(L*26^k) SC is O(L+N)
3public:
4    struct Node{
5        Node* next[26] = {};
6        bool isend = false;
7
8    };
9    Node* root;
10    WordDictionary() {
11        root = new Node();
12        
13    }
14    
15    void addWord(string word) {
16        Node* cur = root;
17        for(int i = 0; i < word.size(); i++){
18            int idx = word[i] - 'a';
19            if(cur->next[idx] == nullptr) cur->next[idx] = new Node();
20            cur = cur->next[idx];
21        }
22        cur->isend = true;
23        
24    }
25    bool dfs(string& word, int idx, Node* cur){
26        if(!cur) return false;
27        if(word.size() == idx ) return cur->isend;
28
29        if(word[idx] == '.'){
30            for(int i = 0; i < 26; i++){
31                if(dfs(word, idx+1, cur->next[i])) return true;
32            }
33            return false;
34        } else {
35            int tdx = word[idx] - 'a';           
36            if(!cur->next[tdx]) return false;
37            if(dfs(word, idx + 1, cur->next[tdx])) return true;
38        }
39        return false;
40         
41    }
42    
43    bool search(string word) {
44        return dfs(word, 0, root);   
45        
46    }
47};
48
49/**
50 * Your WordDictionary object will be instantiated and called as such:
51 * WordDictionary* obj = new WordDictionary();
52 * obj->addWord(word);
53 * bool param_2 = obj->search(word);
54 */