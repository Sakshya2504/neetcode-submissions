class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        // Create graph for 26 characters
        vector<vector<int>> graph(26);
        vector<int> indegree(26, 0);

        // Mark characters that actually exist
        vector<bool> present(26, false);

        for(auto& word : words) {
            for(char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build graph
        for(int i = 0; i < words.size() - 1; i++) {

            string a = words[i];
            string b = words[i + 1];

            int len = min(a.size(), b.size());

            bool found = false;

            for(int j = 0; j < len; j++) {

                if(a[j] != b[j]) {

                    int u = a[j] - 'a';
                    int v = b[j] - 'a';

                    graph[u].push_back(v);
                    indegree[v]++;

                    found = true;
                    break;
                }
            }

            // Invalid case:
            // "abc" comes before "ab"
            if(!found && a.size() > b.size()) {
                return "";
            }
        }

        // Kahn's Algorithm
        queue<int> q;

        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for(auto next : graph[node]) {

                indegree[next]--;

                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Cycle exists
        int totalCharacters = 0;

        for(int i = 0; i < 26; i++) {
            if(present[i]) {
                totalCharacters++;
            }
        }

        if(ans.size() != totalCharacters) {
            return "";
        }

        return ans;
    }
};