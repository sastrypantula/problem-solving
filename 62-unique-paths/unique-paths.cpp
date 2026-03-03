class Solution {
public:
vector<vector<int>> dp;
int func(int i,int j,int m,int n){
    if(j>=n || i>=m){
        return 0;
    }
    if(i==m-1 && j==n-1){
   return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int right=func(i,j+1,m,n);
    int down=func(i+1,j,m,n);
    return dp[i][j]=right+down;
}
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        return func(0,0,m,n);
    }
};