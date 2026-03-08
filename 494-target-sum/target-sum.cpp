class Solution {
public:
vector<vector<int>> dp;
int offset=1000;
int func(int i,int n,vector<int>& nums,int target,int sum){
    if(sum+offset<0 || sum+offset>2*offset+1){
        return 0;
    }
     if(i>=n){
         if(sum==target){
        return 1;
    }
        return 0;
    }
    if(dp[i][sum+offset]!=-1){
        return dp[i][sum+offset];
    }
   int p=func(i+1,n,nums,target,sum+nums[i]);  
   int m=func(i+1,n,nums,target,sum-nums[i]);
   return dp[i][sum+offset]=p+m;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(2*offset+1,-1));
       return func(0,n,nums,target,0);
    }
};