class Solution {
public:
    int helper(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;
        if (index == coins.size())
            return 1e9;
        if (dp[index][amount] != -1)
            return dp[index][amount];

        int notTake = helper(coins, amount, index + 1, dp);

        int take = 1e9;

        if (coins[index] <= amount) {
            take = 1 + helper(coins, amount - coins[index], index, dp);
        }

        return dp[index][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(coins, amount, 0, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};