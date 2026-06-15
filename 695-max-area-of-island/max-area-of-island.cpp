class Solution {
public:
int rows;
int cols;
   int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited){
    int count=0;
    queue<pair<int,int>> q;
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    q.push({i,j});
    visited[i][j]=true;
    while(!q.empty()){
        int n=q.size();
        count+=n;
        while(n--){
            pair<int,int> t=q.front();
            q.pop();
            for(auto it:dirs){
                int x=it[0];
                int y=it[1];
                int x_=x+t.first;
                int y_=y+t.second;
                if(0<=x_ && x_<rows && 0<=y_ && y_<cols && grid[x_][y_]==1 && visited[x_][y_]==false){
                    visited[x_][y_]=true;
                    q.push({x_,y_});
                }
            }
        }

    }
    return count;
   }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int ans=INT_MIN;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                   int temp=bfs(i,j,grid,visited);
                   ans=max(ans,temp);
                }
            }
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};