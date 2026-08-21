class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        for(auto& top : edges){
            graph[top[0]].push_back(top[1]);
            graph[top[1]].push_back(top[0]);
        }
        queue<int> temp;
        temp.push(0);
        while(!temp.empty()){
            int top = temp.front();
            temp.pop();
            if(visited[top] == true) return false;
            visited[top] = true;
            for(auto t : graph[top]){
                if(!visited[t]){
                    temp.push(t);
                } 
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};
