class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto& top : prerequisites){
            graph[top[0]].push_back(top[1]);
            indegree[top[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto qu : graph[temp]){
                indegree[qu]--;
                if(indegree[qu] == 0){
                    q.push(qu);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] != 0){
                return false;
            }
        }
        return true;
    }
};
