class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        if(intervals.empty()) return ans;

        int m = INT_MIN;

        for(int i = 0; i < intervals.size() - 1; i++) {

            int first = intervals[i][1];
            int second = intervals[i + 1][0];

            if(first < second) {
                ans.push_back(intervals[i]);
                m = max(m, intervals[i][1]);
            }
            else {
                int start = intervals[i][0];
                int end = intervals[i][1];

                while(i + 1 < intervals.size() && end >= intervals[i + 1][0]) {
                    end = max(end, intervals[i + 1][1]);
                    i++;
                }

                ans.push_back({start, end});
                m = end;
            }
        }

        if(ans.empty() || ans.back()[1] < intervals.back()[0]) {
            ans.push_back(intervals.back());
        }

        return ans;
    }
};