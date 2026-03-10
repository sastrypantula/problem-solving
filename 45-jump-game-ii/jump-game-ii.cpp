class Solution {
public:
int dp[10001];
int func(int i,int n,vector<int>& nums){
    if(i>=n){
        return 1e9;
    }
    if(i==n-1){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int take=0;
    int res=1e9;
    for(int j=1;(j<=nums[i] && i+j<n);j++){
        take=1+func(i+j,n,nums);
        res=min(res,take);
    }
    return dp[i]=res;

}
    int jump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return func(0,n,nums);
    }
};