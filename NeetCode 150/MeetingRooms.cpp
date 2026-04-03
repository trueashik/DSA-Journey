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
    // Here I have used greedy approach with TC O(nlogn) and SC O(1)
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval&a, Interval&b){
            return a.start < b.start;
        });

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i-1].end > intervals[i].start) return false;
        }
        return true;
        
    }
};
