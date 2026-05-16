class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> mymap;
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            mymap[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res(n+1,INT_MAX);
        vector<int> parent(n+1,-1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        res[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(auto vec:mymap[node]){
                int no=vec.first;
                int d=vec.second;
                if(d+dist<res[no]){
                    res[no]=d+dist;
                    pq.push({d+dist,no});
                    parent[no]=node;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(res[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,res[i]);
        }
      
        return ans;
    }
};