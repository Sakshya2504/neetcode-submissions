class Solution {
public:
    int helper(vector<int>& nums,vector<int>& dp,int i){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int first = nums[i] + helper(nums,dp,i+2);
        int skip = helper(nums,dp,i+1);
        return dp[i] = max(first,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return helper(nums, dp, 0);
    }
};
