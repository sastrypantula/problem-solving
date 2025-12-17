class Solution {
public:
long long dp[1001][501][3];
static const long long NEG=-4e18;
long long solve(int i,int cases,int k,vector<int>& prices){
    if(i>=prices.size()){
        if(cases==0){
            return 0;
        }
        return NEG;// no valid transaction because if buy/sell before now he cant sell/buy as he croseed the array 
    }
    if(k<0){
        return NEG;
    }
    if(dp[i][k][cases]!=NEG){
        return dp[i][k][cases];
    }

   long long skip=solve(i+1,cases,k,prices);
    long long  take=NEG;
    if(k>0){
    if(cases==1){// selling currently assuming case=1 means buyied before 
         take=prices[i]+solve(i+1,0,k-1,prices);
    }
    else if(cases==2){// buying currently assuming case=2 means sold short selling before
        take=-prices[i]+solve(i+1,0,k-1,prices);
    }
    else {
        take=max(prices[i]+solve(i+1,2,k,prices),-prices[i]+solve(i+1,1,k,prices));
    }
    }
    return dp[i][k][cases]=max(take,skip);
} 


    long long maximumProfit(vector<int>& prices, int k) {
         int n=prices.size();
           // initialising the empty vector with INT_MIN
           for(int i=0;i<1001;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=NEG;
                }
            }
           }
           int cases=0;
           return solve(0,cases,k,prices);
    }
};