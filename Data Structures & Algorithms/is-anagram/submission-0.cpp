class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int size = s.size();
        vector<int> vec(26,0);
        for(int i=0;i<size;i++){
            vec[int(s[i] - 'a')] += 1;
            vec[int(t[i] - 'a')] -= 1;
        }
        for(int i=0;i<26;i++){
            if(vec[i] != 0) return false;
        }  
        return true;     
    }
};
