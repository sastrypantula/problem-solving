class Solution {
public:
    const int MOD = 1e9 + 7;

   long long power(long long a,long long b){
      if(b==0){
        return 1;
      }
    long long half=power(a,b/2);
    long long ans=(half*half)%MOD;
    if(b%2==1){
      return (ans*a)%MOD;
    }
    return ans;

   }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mymap;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            mymap[u].push_back(v);
            mymap[v].push_back(u);
        }
        queue<int> q;
        int n=mymap.size();
       vector<bool> visited(n+1,false);
      
        int count=-1;
        q.push(1);
        visited[1]=true;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int u=q.front();
                q.pop();
                for(auto it:mymap[u]){
                    if(visited[it]==false){
                        q.push(it);
                        visited[it]=true;
                    }
                }
                
            }
            count++;
        }
       if(count==0){
        return 1;
       }
       return power(2,count-1);
    }

};