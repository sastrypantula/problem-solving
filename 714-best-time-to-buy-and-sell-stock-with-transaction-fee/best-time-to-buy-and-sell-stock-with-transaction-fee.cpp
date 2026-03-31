class Solution {
public:
vector<vector<int>> dp;
int func(int i,int n,vector<int>& prices,bool buy,int fee){
    if(i>=n){
        return 0;
    }
    int ans=0;
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
        int buy_now=-prices[i]+func(i+1,n,prices,!buy,fee);
        int buy_after=func(i+1,n,prices,buy,fee);
        ans=ans+max(buy_now,buy_after);
    }
    else{
         int sell_now=+prices[i]-fee+func(i+1,n,prices,!buy,fee);
        int sell_after=func(i+1,n,prices,buy,fee);
        ans=ans+max(sell_now,sell_after);
    }
    return dp[i][buy]=ans;
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        bool buy=true;
        dp.resize(n,vector<int>(2,-1));
        return func(0,n,prices,buy,fee);
    }
};