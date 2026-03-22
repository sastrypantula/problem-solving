class Solution {
public:
vector<vector<int>> dp;
int func(vector<int>& nums, int target,int xori,int i){
     if(i>=nums.size()){
        if(xori==target){
            return 0;
        }
        return 1e9;
     }
     if(dp[i][xori]!=-1){
        return dp[i][xori];
     }
    int take=func(nums,target,xori^nums[i],i+1);
    int skip=1+func(nums,target,xori,i+1);
return dp[i][xori]=min(take,skip);
}
    int minRemovals(vector<int>& nums, int target) {
        int xori=0;
        for(int i:nums){
            xori=xori^i;
        }
        if(xori==target) return 0;
        int n=nums.size();
        dp.resize(n,vector<int>(16384,-1));
        int ans= func(nums,target,0,0);
        if(ans>=1e9) return -1;
        return ans;
    }
};