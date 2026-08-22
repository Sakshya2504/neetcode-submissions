// class Solution {
// public:
//     bool helper(string& s, vector<vector<int>>& dp, int i, int j) {
        
//         // Empty or single character
//         if (i >= j)
//             return true;

//         // Already calculated
//         if (dp[i][j] != -1)
//             return dp[i][j];

//         // First and last character must match
//         if (s[i] != s[j])
//             return dp[i][j] = false;

//         return dp[i][j] = helper(s, dp, i + 1, j - 1);
//     }

//     int countSubstrings(string s) {
//         int n = s.size();

//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {

//                 if (helper(s, dp, i, j)) {
//                     ans++;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int ans = 0;

        // Length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ans++;
        }

        // Length 2 to n
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    if (len == 2) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};