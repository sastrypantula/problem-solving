class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>> q;
        int ones=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                q.push({i,j});
                }
                else if(grid[i][j]==1){
                    ones++;
                }
            }
        }
        if(ones==0){
            return 0;
        }
      if(q.size()==0){
        return -1;
      }

      int count=0;
      vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
      while(!q.empty()){
           int n=q.size();
           while(n--){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(auto it:dirs){
                int x=i+it[0];
                int y=j+it[1];
                if(0<=x && x<rows && 0<=y && y<cols){
                    if(grid[x][y]!=2 && grid[x][y]!=0){
                        q.push({x,y});
                        grid[x][y]=2;
                    }
                }
            }
           }
           count++;
      }
      
      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
      }

      return count-1;
    }
};