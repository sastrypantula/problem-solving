class Solution {
public:

vector<int> dp;
int func(int i,int n){
    if(i>n){
        return 0;
    }
    if(i==n){
        return 1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int one=0;
    int two=0;
    if(i+1<=n){
     one=func(i+1,n);
    }
    if(i+2<=n){
     two=func(i+2,n);
    }
    
    return dp[i]=one+two;
}
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return func(0,n);
    }
};