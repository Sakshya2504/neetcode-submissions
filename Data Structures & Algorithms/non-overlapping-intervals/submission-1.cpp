class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        int count = 0;
        int last = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(last > intervals[i][0]) {
                count++;

                // Keep the interval that ends earlier
                last = min(last, intervals[i][1]);
            }
            else {
                last = intervals[i][1];
            }
        }

        return count;
    }
};