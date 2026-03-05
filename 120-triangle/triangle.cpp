class Solution {
public:
vector<vector<int>> dp;
int func(int i,int j,vector<vector<int>>& grid){
    if(i>=grid.size()){
        return 0;
    }
      if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
   
    int take_i=grid[i][j]+func(i+1,j,grid);
    int take_i1=grid[i][j]+func(i+1,j+1,grid);
    return dp[i][j]=min(take_i,take_i1);
   
}
    int minimumTotal(vector<vector<int>>& triangle) {
       int m=triangle.size();
       int n=triangle[m-1].size();
       dp.resize(m,vector<int>(n,INT_MAX));
       return func(0,0,triangle); 
    }
};