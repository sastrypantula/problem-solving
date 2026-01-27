class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,2*dist});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int u=pq.top().first;
            int d=pq.top().second;
            pq.pop();
            for(auto& v:adj[u]){
                int node=v.first;
                int cost=v.second;
                if(d+cost<dist[node]){
                    dist[node]=d+cost;
                    pq.push({node,dist[node]});
                }
            }

        }
        if(dist[n-1]==INT_MAX){
            return -1;
        }
            return dist[n-1];
    }
};