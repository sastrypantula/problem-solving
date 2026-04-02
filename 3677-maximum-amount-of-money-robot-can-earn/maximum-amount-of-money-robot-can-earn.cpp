class Solution {
public:
int m;
int n;
vector<vector<vector<int>>> dp;
int func(int i,int j,int m,int n,int count,vector<vector<int>>& coins){
    if(i==m-1 && j==n-1){
       if(count<2 && coins[i][j]<0){
        return dp[i][j][count]=0;
       }
       return dp[i][j][count]=coins[i][j];
    }
    if(i>=m || j>=n){
        return -1e9;
    }
    if(dp[i][j][count]!=INT_MIN){
        return dp[i][j][count];
    }
    int ans=0;
    if(coins[i][j]>=0){
        int right=coins[i][j]+func(i,j+1,m,n,count,coins);
        int down=coins[i][j]+func(i+1,j,m,n,count,coins);
        ans=max(down,right);
    }
    if(coins[i][j]<0){
        if(count<2){
            int right_neu=0+func(i,j+1,m,n,count+1,coins);
            int down_neu=0+func(i+1,j,m,n,count+1,coins);
            int right=coins[i][j]+func(i,j+1,m,n,count,coins);
            int down=coins[i][j]+func(i+1,j,m,n,count,coins);
            ans=max({right_neu,down_neu,right,down});
        }
        else{
        int right=coins[i][j]+func(i,j+1,m,n,count,coins);
        int down=coins[i][j]+func(i+1,j,m,n,count,coins);
        ans=max(down,right);
        }
    }
    return dp[i][j][count]=ans;
}
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();
        n=coins[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        int count=0;
        return func(0,0,m,n,count,coins);
    }
};