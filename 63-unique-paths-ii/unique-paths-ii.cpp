class Solution {
public:
vector<vector<int>> dp;
int func(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid){
     if(i>=m || j>=n || obstacleGrid[i][j]==1){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return 1;
    }
  
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right=func(i,j+1,m,n,obstacleGrid);
    int down=func(i+1,j,m,n,obstacleGrid);
    return dp[i][j]=right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return func(0,0,m,n,obstacleGrid);
    }
};