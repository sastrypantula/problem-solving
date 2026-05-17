class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs={{0,1},{0,-1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
        queue<pair<int,int>> que;
        que.push({0,0});
        
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        if(grid[0][0]==1 || grid[rows-1][cols-1]==1){
            return -1;
        }
        grid[0][0]=1;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                int x=que.front().first;
                int y=que.front().second;
                if(x==rows-1 && y==cols-1){
                    return count+1;
                }
                que.pop();
                grid[x][y]=1;
                for(auto it:dirs){
                    int i=it.first;
                    int j=it.second;
                    if(0<=x+i && x+i<rows && y+j<cols && 0<=y+j){
                        if(grid[x+i][y+j]!=1){
                            que.push({x+i,y+j});
                            grid[x+i][y+j]=1;
                        }
                    }
                }
              
            }
              count++;

        }
        return -1;
    }
};