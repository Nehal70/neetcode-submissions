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
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<Interval> sortedIntervals = intervals;
        sort(sortedIntervals.begin(), sortedIntervals.end(), [](const Interval& a, const Interval& b){
            if (a.start == b.start) {
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        for (int i = 1; i < sortedIntervals.size(); i++) {
            if (sortedIntervals[i].start < sortedIntervals[i - 1].end) {
                return false;
            }
        }
        return true;
    }
};
