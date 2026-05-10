class Solution {
public:
int n;
int func(int i,vector<int>& nums,int target,vector<int>& dp){
if(i==n-1){
    return 0;
}
if(dp[i]!=INT_MIN){
    return dp[i];
}
    int res=INT_MIN;

    for(int j=i+1;j<n;j++){
        if(-1*target<=nums[j]-nums[i] && nums[j]-nums[i]<=target){
           int ans=1+func(j,nums,target,dp);
            res=max(res,ans);
        }
    }
    return dp[i]=res;
}
    int maximumJumps(vector<int>& nums, int target) {
        n=nums.size();
        vector<int> dp(n+1,INT_MIN);
       long long ans=func(0,nums,target,dp);
        if(ans<0){
            return -1;
        } 
        return (int)ans;
    }
};