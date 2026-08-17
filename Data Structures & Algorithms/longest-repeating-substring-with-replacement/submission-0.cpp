class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vec(26, 0);

        int i = 0;
        int j = 0;
        int ans = 0;
        int maxFreq = 0;

        while (j < s.size()) {

            vec[s[j] - 'A']++;

            maxFreq = max(maxFreq, vec[s[j] - 'A']);
            int windowSize = j - i + 1;
            int replace = windowSize - maxFreq;

            if (replace <= k) {
                ans = max(ans, windowSize);
                j++;
            }
            else {
                vec[s[i] - 'A']--;
                i++;
                j++;
            }
        }

        return ans;
    }
};