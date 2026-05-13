class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mymap;
        int n=numCourses;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
             int v=prerequisites[i][0];
             mymap[u].push_back(v);
        }
        vector<int> indegree(n,0);
        for(auto it:mymap){
            vector<int> adj=it.second;
            for(auto v:adj){
                indegree[v]++;
            }
        }
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        vector<int> res;
  
        while(!que.empty()){
            int u=que.front();
            que.pop();
                  res.push_back(u);
            for(auto v:mymap[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        if(res.size()==n){
            return res;
        }
        return {};
    }
};