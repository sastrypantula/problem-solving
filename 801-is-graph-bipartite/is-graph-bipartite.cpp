class Solution {
public:
   unordered_map<int,vector<int>> mymap;
//    bool dfs(int i,vector<int>& color,int curr){

//     color[i]=curr;
//     for(auto it:mymap[i]){
//         if(color[it]==-1){
//             if(dfs(it,color,1-curr)==false){
//                 return false;
//             }
//         }
//         else if(color[it]==curr){
//             return false;
//         }
//     }
//     return true;
//    }
    bool isBipartite(vector<vector<int>>& graph) {
     
        for(int i=0;i<graph.size();i++){
           for(auto& it:graph[i]){
            mymap[i].push_back(it);
           }
        }
        int n=graph.size();
        vector<int> color(n,-1);
        // for(int i=0;i<n;i++){
        //     if(color[i]==-1){
        //         if(dfs(i,color,0)==false){
        //             return false;
        //         }
        //     }
        // }
        // return true;
        
        //BFS approach 
        for(int i=0;i<n;i++){
            if(color[i]==-1){
        queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
            int node=q.front();
            q.pop();

            for(auto& it:mymap[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=1-color[node];
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
            }
        }
            }
        }
        return true;
    }
};