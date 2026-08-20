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
        if(intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(),[](Interval &a,Interval &b){
            return a.start < b.start;}
        );
        for(int i=0;i<intervals.size()-1;i++){
            int first = intervals[i].end;
            int second = intervals[i + 1].start;
            if(first > second) return false;
        }
        return true;
    }
};
