class Solution {
public:
  int func(int i,int n,bool buy,vector<int>& prices, vector<vector<int>>& dp){
    if(i>=n){
         return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int ans=0;
    if(buy==true){
    int take=-prices[i]+func(i+1,n,false,prices,dp); // taken for buying it
    int skip=func(i+1,n,true,prices,dp); // not taken to buy think to buy in future
    ans=max(take,skip);
    }
    else{
        int take=prices[i]+func(i+1,n,true,prices,dp);
        int skip=func(i+1,n,false,prices,dp);
        ans=max(take,skip);
    }
    return dp[i][buy]=ans;
  }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=true;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,n,buy,prices,dp);
    }
};