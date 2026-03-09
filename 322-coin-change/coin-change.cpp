class Solution {
public:
int dp[13][10001];
int func(int i,int n,vector<int>& coins,int amount){
if(amount==0){
    return 0;
}
if(amount<0 || i>=n){
    return 1e9;
}
if(dp[i][amount]!=-1){
    return dp[i][amount];
}
int take=1e9;
if(coins[i]<=amount){
    take=1+func(i,n,coins,amount-coins[i]);
}
int skip=func(i+1,n,coins,amount);
return dp[i][amount]=min(take,skip);

}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
     int ans=func(0,n,coins,amount);
     if(ans>=1e9){
        return -1;
     }
     return ans;
    }
};