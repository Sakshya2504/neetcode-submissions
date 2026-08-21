class Solution {
public:
    void validTree(int n, vector<vector<int>>& graph,vector<bool> &visited) {
        queue<int> temp;
        temp.push(n);
        while(!temp.empty()){
            int top = temp.front();
            temp.pop();
     
            for(auto t : graph[top]){
                if(!visited[t]){
                    visited[t] = true;
                    temp.push(t);
                } 
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& top : edges){
            graph[top[0]].push_back(top[1]);
            graph[top[1]].push_back(top[0]);
        }
        vector<bool> visited(n,false);
        int ans = 0;

        for(int i=0;i<graph.size();i++){
                if(!visited[i]){
                    ans++;
                    validTree(i,graph,visited);
                }
        }
        return ans;
    }
};
