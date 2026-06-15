class Solution {
public:
    unordered_map<int,vector<int>> mymap;
bool dfs(int i,int curr,vector<int>& color){
    color[i]=curr;
    for(auto it:mymap[i]){
        if(color[it]==-1){
            if(dfs(it,1-curr,color)==false){
                return false;
            }
        }
        else if(color[it]==curr){
            return false;
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
   
       for(int i=0;i<dislikes.size();i++){
        int u=dislikes[i][0];
        int v=dislikes[i][1];
        mymap[v].push_back(u);
        mymap[u].push_back(v);
       } 
       vector<int> color(n+1,-1);
       for(int i=0;i<n;i++){
        if(color[i]==-1){
        if(dfs(i,0,color)==false){
            return false;
        }
        }
       }
       return true;
    }
};