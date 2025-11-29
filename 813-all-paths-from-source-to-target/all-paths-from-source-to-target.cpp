class Solution {
public:
int n;
vector<vector<int>> res;
void func(int src,vector<vector<int>>& graph,vector<int>& temp){
if(src==n){
    temp.push_back(src);
    res.push_back(temp);
    temp.pop_back();

}
else{
    temp.push_back(src);
    vector<int> l=graph[src];
    for(int it:l){
        func(it,graph,temp);
    }
    temp.pop_back();
}
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      
         n=graph.size()-1;
         vector<int> t=graph[0];
     
        for(int src:t){
          vector<int> temp;
          temp.push_back(0);
          func(src,graph,temp);
        }
        return res;
    }
};