class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
            }
            else {
                if(sta.empty()) {
                    return false;
                }

                char top = sta.top();

                if((s[i] == ')' && top != '(') ||
                   (s[i] == ']' && top != '[') ||
                   (s[i] == '}' && top != '{')) {
                    return false;
                }

                sta.pop();
            }
        }

        return sta.empty();
    }
};