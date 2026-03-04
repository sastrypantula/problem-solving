class Solution {
public:
vector<vector<int>> dp;
int func(int i,int j,int m,int n,vector<vector<int>>& grid){
   if(i>=m || j>=n){
    return 1e9;
   }
   if(dp[i][j]!=-1){
    return dp[i][j];
   }
   if(i==m-1 && j==n-1){
    return grid[i][j];
   }
   int right=grid[i][j]+func(i,j+1,m,n,grid);
   int down=grid[i][j]+func(i+1,j,m,n,grid);
   return dp[i][j]=min(right,down);

}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return func(0,0,m,n,grid);
    }
};