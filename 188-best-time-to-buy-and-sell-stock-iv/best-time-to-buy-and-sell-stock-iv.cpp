class Solution {
public:
int func(int i,int n,vector<int>& prices,bool buy,int count,int k,vector<vector<vector<int>>>& dp){
    if(i>=n || count>=k){
        return 0;
    }
    if(dp[i][count][buy]!=-1){
        return dp[i][count][buy];
    }
    int ans=0;
    if(buy){
        if(count<k){
    int buynow=-prices[i]+func(i+1,n,prices,false,count,k,dp);
    int buyafter=func(i+1,n,prices,true,count,k,dp);
      ans=ans+max(buynow,buyafter);
        }
    }
    else{
    int sellnow=prices[i]+func(i+1,n,prices,true,count+1,k,dp);
    int sellafter=func(i+1,n,prices,false,count,k,dp);
    ans=ans+max(sellnow,sellafter);
    }
    return dp[i][count][buy]=ans;
}
    int maxProfit(int k, vector<int>& prices) {
        bool buy=true;
        int count=0;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k,vector<int>(2,-1)));
        return func(0,n,prices,buy,count,k,dp);
    }
};