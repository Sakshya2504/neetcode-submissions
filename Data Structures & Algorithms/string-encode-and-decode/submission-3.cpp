class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for (int i = 0; i < strs.size(); i++) {
            ans += to_string(strs[i].size());
            ans += '#';
            ans += strs[i];
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        int size = s.size();
        int i = 0;

        while (i < size) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            j++;

            string temp = s.substr(j, len);
            vec.push_back(temp);

            i = j + len;
        }

        return vec;
    }
};