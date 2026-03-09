class Solution {
public:
const int mod=1e9+7;
int dp[201][201][2];
int func(int zero,int one,bool last_is_one,int limit){
if(zero==0 && one==0){
    return 1;
}
if(dp[zero][one][last_is_one]!=-1){
    return dp[zero][one][last_is_one];
}
int result=0;
if(last_is_one==true){
    for(int i=1;i<=min(limit,zero);i++){
        result=(result+func(zero-i,one,false,limit))%mod;
    }
}
if(last_is_one==false){
    for(int i=1;i<=min(limit,one);i++){
        result=(result+func(zero,one-i,true,limit))%mod;
    }
}
return dp[zero][one][last_is_one]=result;
}
    int numberOfStableArrays(int zero, int one, int limit) {
        // main concept here is we can continously put ones or zeros till limit only 
        // after the limit we should try with another number 
        memset(dp,-1,sizeof(dp));
        int start_with_ones=func(zero,one,false,limit);
        int start_with_zeros=func(zero,one,true,limit);
        return ((start_with_ones)%mod+(start_with_zeros)%mod)%mod;
    }
};