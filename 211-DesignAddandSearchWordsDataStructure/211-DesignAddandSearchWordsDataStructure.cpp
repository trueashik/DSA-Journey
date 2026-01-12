// Last updated: 1/12/2026, 7:38:48 PM
1class WordDictionary {
2public:
3    struct Node{
4        Node* next[26] = {};
5        bool isend = false;
6
7    };
8    Node* root;
9    WordDictionary() {
10        root = new Node();
11        
12    }
13    
14    void addWord(string word) {
15        Node* cur = root;
16        for(int i = 0; i < word.size(); i++){
17            int idx = word[i] - 'a';
18            if(cur->next[idx] == nullptr) cur->next[idx] = new Node();
19            cur = cur->next[idx];
20        }
21        cur->isend = true;
22        
23    }
24    bool dfs(string& word, int idx, Node* cur){
25        if(!cur) return false;
26        if(word.size() == idx ) return cur->isend;
27
28        if(word[idx] == '.'){
29            for(int i = 0; i < 26; i++){
30                if(dfs(word, idx+1, cur->next[i])) return true;
31            }
32            return false;
33        } else {
34            int tdx = word[idx] - 'a';           
35            if(!cur->next[tdx]) return false;
36            if(dfs(word, idx + 1, cur->next[tdx])) return true;
37        }
38        return false;
39         
40    }
41    
42    bool search(string word) {
43        return dfs(word, 0, root);   
44        
45    }
46};
47
48/**
49 * Your WordDictionary object will be instantiated and called as such:
50 * WordDictionary* obj = new WordDictionary();
51 * obj->addWord(word);
52 * bool param_2 = obj->search(word);
53 */