class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vec(26, 0);

        int i = 0;
        int j = 0;
        int ans = 0;
        int maxFreq = 0;
        // This means which can be replaced 
        while (j < s.size()) {

            vec[s[j] - 'A']++;
            // To store the frequencey of every letter 

            maxFreq = max(maxFreq, vec[s[j] - 'A']);
            // To check the value of max frequency

            int windowSize = j - i + 1;
            // Window Size which is required

            int replace = windowSize - maxFreq;
            // The aphabets to replace 

            if (replace <= k) {
                // Condition given in the quesiton
                ans = max(ans, windowSize);
                j++;
            }
            else {
                // Shrinking the window
                vec[s[i] - 'A']--;
                i++;
                j++;
            }
        }

        return ans;
    }
};