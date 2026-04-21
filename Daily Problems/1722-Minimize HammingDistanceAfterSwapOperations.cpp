class Solution {
    // Here I have used DSU approach with TC O(n*log(n)) and SC O(n)
public:
    int find(vector<int>& parent, int x){
        if(parent[x] != x){
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    void unite(vector<int>& parent, int a, int b){
        parent[find(parent, a)] = find(parent, b);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int mismatch = 0;
        int n = source.size();
        vector<int>parent(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(auto& v : allowedSwaps){
            unite(parent, v[0], v[1]);
        }
        unordered_map<int, vector<int>>groups;
        for(int i = 0; i < n; i++){
            groups[find(parent, i)].push_back(i);
        }
        
        for(auto& g : groups){
            unordered_map<int, int>freq;
            for(int i : g.second){
                freq[source[i]]++;
                freq[target[i]]--;
            }
            for(auto& f : freq){
                if(f.second > 0) mismatch += f.second;
            }
        }
        return mismatch;
    }
};