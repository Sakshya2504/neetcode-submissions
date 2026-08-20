class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < intervals.size(); i++) {
            if(!pq.empty() && pq.top() <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};