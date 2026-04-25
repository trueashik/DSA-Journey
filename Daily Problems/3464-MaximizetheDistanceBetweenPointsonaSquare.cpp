class Solution {
    // Here I have used binary search approach with TC O(n log n) and SC O(n)
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;
        for (auto& p : points) {
            long long x = p[0], y = p[1];
            if (y == 0) pos.push_back(x);
            else if (x == side) pos.push_back(side + y);
            else if (y == side) pos.push_back(2LL * side + (side - x));
            else pos.push_back(3LL * side + (side - y));
        }

        sort(pos.begin(), pos.end());

        int n = pos.size();
        long long pem = 4LL * side;

        vector<long long> extended = pos;
        for (long long x : pos) extended.push_back(x + pem);
        auto can = [&](long long d) {
            vector<int> nxt(2 * n);
            int j = 0;
            for (int i = 0; i < 2 * n; i++) {
                while (j < 2 * n && extended[j] - extended[i] < d) {
                    j++;
                }
                nxt[i] = j;
            }

            int first_jump = nxt[0];
            for (int start = 0; start <= first_jump && start < n; start++) {
                int curr = start;
                int count = 1;
                while (count < k && curr < 2 * n) {
                    curr = nxt[curr];
                    count++;
                }
                
                if (count == k && curr < 2 * n) {
                    if (extended[curr] - extended[start] <= pem - d) {
                        return true;
                    }
                }
            }
            return false;
        };
        long long low = 0, high = 2LL * side, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2; 

            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};