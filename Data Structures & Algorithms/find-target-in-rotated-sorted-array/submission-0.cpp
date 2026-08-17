class Solution {
public:
    int search(vector<int>& ans, int target) {
        int s = 0, e = ans.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (ans[mid] == target) return mid;
            if (ans[s] <= ans[mid]) {
                if (target >= ans[s] && target < ans[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            
            else {
                if (target > ans[mid] && target <= ans[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
