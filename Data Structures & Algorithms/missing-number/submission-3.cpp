// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] != i) return i;
//         }
//         return nums.size();
//     }
// };
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for(int i = 0; i < n; i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};