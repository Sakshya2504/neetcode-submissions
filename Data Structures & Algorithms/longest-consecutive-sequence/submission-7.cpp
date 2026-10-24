// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.empty()) return 0;
//         int count = 0;
//         int ans = 0;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i] == nums[i+1]-1){
//                 count++;
//                 ans = max(ans,count);
//             }
//             else if(nums[i] == nums[i+1]){
//                 continue;
//             } 
//             else{
//                 count = 0;
//             }
//         }
//         return ans + 1;
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            // Start only if num is the beginning of a sequence
            if (st.find(num - 1) == st.end()) {
                int currNum = num;
                int currLen = 1;

                while (st.find(currNum + 1) != st.end()) {
                    currNum++;
                    currLen++;
                }

                longest = max(longest, currLen);
            }
        }

        return longest;
    }
};