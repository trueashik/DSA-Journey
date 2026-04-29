class Solution {
    // Here I have used DP approach with TC O(n^3) and SC O(n^2)
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                prefix[j][i + 1] = prefix[j][i] + grid[i][j];
            }
        }


        vector<long long> prevPick(n + 1, 0);
        vector<long long> prevSkip(n + 1, 0);


        for (int j = 1; j < n; ++j) {
            vector<long long> currPick(n + 1, 0);
            vector<long long> currSkip(n + 1, 0);

            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    if (curr > prev) {
                        long long score = prefix[j - 1][curr] - prefix[j - 1][prev];
                        currPick[curr] = max(currPick[curr], prevSkip[prev] + score);
                        currSkip[curr] = max(currSkip[curr], prevSkip[prev] + score);
                    } else {
                        long long score = prefix[j][prev] - prefix[j][curr];
                        currPick[curr] = max(currPick[curr], prevPick[prev] + score);
                        
                        currSkip[curr] = max(currSkip[curr], prevPick[prev]);
                    }
                }
            }
            prevPick = move(currPick);
            prevSkip = move(currSkip);
        }
        long long ans = 0;
        for (long long val : prevPick) {
            ans = max(ans, val);
        }
        return ans;
    }
};