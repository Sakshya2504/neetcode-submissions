class Solution {
public:
    int helper(string& s, int index, vector<int>& dp) {

        if (index == s.size())
            return 1;
        if (s[index] == '0')
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int one = helper(s, index + 1, dp);
        int two = 0;

        if (index + 1 < s.size()) {

            int num = (s[index] - '0') * 10 + 
                      (s[index + 1] - '0');

            if (num >= 10 && num <= 26) {
                two = helper(s, index + 2, dp);
            }
        }

        return dp[index] = one + two;
    }

    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return helper(s, 0, dp);
    }
};