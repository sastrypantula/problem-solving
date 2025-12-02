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

void topo(int src,vector<bool>& visi2,vector<vector<int>>& prerequisites,stack<int>& s){
visi2[src]=true;
for(int i=0;i<prerequisites.size();i++){
    int u=prerequisites[i][1];
    int v=prerequisites[i][0];
    if(src==u){
        if(!visi2[v]){
            topo(v,visi2,prerequisites,s);
        }
    }
}
s.push(src);
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           int V=numCourses;
           vector<int>res;
        vector<bool>visited(V,false);
        vector<bool>recpath(V,false);
        for(int i=0;i<V;i++){

        if(isCycle(i,visited,recpath,prerequisites)){
            return res;
        }
        }
        vector<bool>visi2(V,false);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!visi2[i])
           topo(i,visi2,prerequisites,s);
        }
        while(s.size()>0){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};