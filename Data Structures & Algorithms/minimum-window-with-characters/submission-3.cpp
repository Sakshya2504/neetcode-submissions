class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int i = 0;
        int j = 0;
        int count = t.size();
        int start = 0;
        int minLen = INT_MAX;

        while (j < s.size()) {
            if (freq[s[j]] > 0) {
                count--;
            }

            freq[s[j]]--;
            j++;

            while (count == 0) {
                if (j - i < minLen) {
                    minLen = j - i;
                    start = i;
                }

                freq[s[i]]++;

                if (freq[s[i]] > 0) {
                    count++;
                }

                i++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};