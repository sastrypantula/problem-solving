class Solution {
public:
bool dfs(int u,int dest,vector<bool>& visited,vector<list<int>>& l){
    if(u==dest){
        return true;
    }
    visited[u]=true;
    for(auto it:l[u]){
        if(!visited[it]){
           if (dfs(it, dest, visited, l)) {
            return true;
        }

        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>>l(n);
        int N=edges.size();
        for(int i=0;i<N;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            l[u].push_back(v);
              l[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return dfs(source,destination,visited,l);
    }
};