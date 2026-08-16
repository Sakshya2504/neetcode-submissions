class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int end = s.size()-1;
        int start = 0;
        while(start<end){
            while(start < end && !isalnum(s[start])) {
                start++;
            }
            while(start < end && !isalnum(s[end])) {
                end--;
            }
            if(tolower(s[start]) == tolower(s[end])){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
