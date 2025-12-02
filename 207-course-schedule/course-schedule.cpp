class Solution {
public:
bool isCycle(int src,vector<bool>& visited,vector<bool>& recpath,vector<vector<int>>& prerequisites){
    visited[src]=true;
    recpath[src]=true;
    for(int i=0;i<prerequisites.size();i++){
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];
        if(u==src){
            if(!visited[v]){
                if(isCycle(v,visited,recpath,prerequisites)){
                    return true;
                }
            }
            else{
              if(recpath[v]){
                return true;
              }  
            }
        }
    }
    recpath[src]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<bool>visited(V,false);
        vector<bool>recpath(V,false);
        for(int i=0;i<V;i++){ // here checking for all components as the graph may be disconnected.
        
        if(isCycle(i,visited,recpath,prerequisites)){
            return false;
        }
        }
        return true;

    }
 
};