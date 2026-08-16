class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count = 0;
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]-1){
                count++;
                ans = max(ans,count);
            }
            else if(nums[i] == nums[i+1]){
                continue;
            } 
            else{
                count = 0;
            }
        }
        return ans + 1;
    }
};
