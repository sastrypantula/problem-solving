class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>visited(V,false);
        int mstcost=0;
        int src=0;
        pq.push(make_pair(0,src));
        while(pq.size()>0){
            auto [cost,u]=pq.top();
            pq.pop();
            if(!visited[u]){
                visited[u]=true;
                mstcost+=cost;
                for(int v=0;v<V;v++){
                    if(!visited[v]){
                        int dist=abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                       
                        pq.push({dist,v});
                    }
                }
            }
        }
        return mstcost;
    }
};