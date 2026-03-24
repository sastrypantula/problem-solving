class Solution {
public:
int func(int i,int n,int count,vector<int>& prices,bool buy,vector<vector<vector<int>>>& dp){
     if(i>=n || count>=2) return 0;
     if(dp[i][count][buy]!=-1){
        return dp[i][count][buy];
     }
    int ans=0;
    if(buy==true){
       if(count<2){
       int take=-prices[i]+func(i+1,n,count,prices,false,dp);
       int skip=func(i+1,n,count,prices,true,dp);
       ans=max(take,skip);
       }
    }
    else{
        int take=prices[i]+func(i+1,n,count+1,prices,true,dp);
        int skip=func(i+1,n,count,prices,false,dp);
        ans=max(take,skip);
    }
    return dp[i][count][buy]=ans;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int count=0;
        bool buy=true;
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return func(0,n,count,prices,buy,dp);
    }
};