class DetectSquares {
    // Here I have used hashmap approach with TC O(1) for add and O(n) for count and SC O(n)
public:
    unordered_map<long long, int> ump;

    long long getKey(int x, int y){
        return ((long long)x << 32) | (unsigned int)y;
    }
    
    void add(vector<int> point) {
        ump[getKey(point[0], point[1])]++;        
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int res = 0;

        for (auto &m : ump) {
            int x = (int)(m.first >> 32);
            int y = (int)(m.first & 0xffffffff);

            // correct condition
            if (abs(px - x) == abs(py - y) && px != x) {
                auto it1 = ump.find(getKey(x, py));
                auto it2 = ump.find(getKey(px, y));
                int c1 = it1 != ump.end() ? it1->second : 0;
                int c2 = it2 != ump.end() ? it2->second : 0;

                res += c1 * c2 * m.second;
            }
        }   

        return res;     
    }
};