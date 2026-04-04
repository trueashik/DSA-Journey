/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    // Here I have used two pointer approach with TC O(nlogn) and SC O(n)
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int ans = 0;
        vector<int> start(n), end(n);
        for(int i = 0; i < n; i++){
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0, curr = 0;
        while(i < n){
            if(start[i] < end[j]){
                i++;
                curr++;
            }else{
                curr--;
                j++;
            }
            ans = max(curr, ans);
        }
        return ans;
    }
};
