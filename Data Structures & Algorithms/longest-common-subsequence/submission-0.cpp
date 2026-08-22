class Solution {
public:
    int helper(string& text1, string& text2,
               int i, int j, vector<vector<int>>& dp) {

        // No characters left
        if (i < 0 || j < 0)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + helper(text1, text2, i - 1, j - 1, dp);
        }

        // Characters don't match
        int first = helper(text1, text2, i - 1, j, dp);
        int second = helper(text1, text2, i, j - 1, dp);

        return dp[i][j] = max(first, second);
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(text1, text2, m - 1, n - 1, dp);
    }
};