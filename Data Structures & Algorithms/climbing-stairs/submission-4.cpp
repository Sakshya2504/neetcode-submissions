class Solution {
public:

    int helper(int n, int sum, vector<int>& dp) {

        if(sum == n) {
            return 1;
        }

        if(sum > n) {
            return 0;
        }

        if(dp[sum] != -1) {
            return dp[sum];
        }

        int one = helper(n, sum + 1, dp);
        int two = helper(n, sum + 2, dp);
        return dp[sum] = one + two;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, 0, dp);
    }
};