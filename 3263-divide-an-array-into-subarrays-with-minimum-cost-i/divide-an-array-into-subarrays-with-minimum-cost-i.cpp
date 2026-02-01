class Solution {
public:
  int solve(int i,int n,vector<int>& nums){
    int mini=INT_MAX;
    for(int j=i;j<n;j++){
        mini=min(mini,nums[j]);
    }
    return mini;
  }
    int minimumCost(vector<int>& nums) {
       int ans=INT_MAX;
       int n=nums.size();
    
       for(int i=1;i<n-1;i++){
        int a=nums[0];
        int b=nums[i];
        int c=solve(i+1,n,nums);
        if(a+b+c<ans){
            ans=a+b+c;
        }
       }
       return ans;
    }
};