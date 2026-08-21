class Solution {
public:
    int helper(vector<int>& nums,vector<int>& dp,int i,int end){
        if(i > end) return 0;
        if(dp[i] != -1) return dp[i];
        int first = nums[i] + helper(nums,dp,i+2,end);
        int skip = helper(nums,dp,i+1,end);
        return dp[i] = max(first,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        int first = helper(nums, dp1, 0, n - 2);
        vector<int> dp2(n, -1);
        int second = helper(nums, dp2, 1, n - 1);
        return max(first,second);
    }
};
