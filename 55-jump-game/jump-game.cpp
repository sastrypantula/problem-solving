class Solution {
public:
int dp[10001];
   bool func(int i,int n,vector<int>& nums){
    if(i==n-1){
        return true;
    }
    if(i>=n){
        return false;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    bool take=false;
    bool res=false;
    for(int j=1;j<=nums[i];j++){
        take=func(i+j,n,nums);
         if(take==true){
            res=true;
            return dp[i]=true;
         }
    }
    return dp[i]=res || take;

   }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return func(0,n,nums);
    }
};