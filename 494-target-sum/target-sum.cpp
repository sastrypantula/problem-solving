class Solution {
public:
int ans=0;
int func(int i,int n,vector<int>& nums,int target,int sum){
     if(i>=n){
         if(sum==target){
        return 1;
    }
        return 0;
    }
   int p=func(i+1,n,nums,target,sum+nums[i]);  
   int m=func(i+1,n,nums,target,sum-nums[i]);
   return p+m;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       return func(0,n,nums,target,0);
    }
};