class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> res(rows,vector<int>(cols,INT_MAX));
       vector<vector<bool>> visited(rows,vector<bool>(cols,false));
          queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                 if(mat[i][j]==0){
                    res[i][j]=0; 
                 
                    q.push({i,j});
                    visited[i][j]=true;
                 }
            }
        }
                int steps=0;
                    while(!q.empty()){
                        int n=q.size();
                        while(n--){
                          pair<int,int> p=q.front();
                          q.pop();
                          int i_=p.first;
                          int j_=p.second;
                         
                          for(auto it:dirs){
                            int x=i_+it[0];
                            int y=j_+it[1];
                            if(0<=x && x<rows && 0<=y && y<cols){
                                    if(visited[x][y]==false && mat[x][y]==1){
                                        visited[x][y]=true;
                                        res[x][y]=steps+1;
                                        q.push({x,y});
                                    }
                            }
                          }
                        }
                        steps++;
                    }
                 
            
        return res;

    }
};