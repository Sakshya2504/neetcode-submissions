class Solution { 
public: 
    int lengthOfLongestSubstring(string s) { 
        vector<int> vec(255, 0); 
        int i = 0; 
        int j = 0; 
        int ans = 0; 
 
        while (j < s.size()) { 
            if (vec[s[j]] == 0) { 
                vec[s[j]]++; 
                j++; 
            } 
            else { 
                ans = max(ans, j - i); 
                vec[s[i]]--; 
                i++; 
            } 
        } 
 
        ans = max(ans, j - i); 
        return ans; 
    } 
};