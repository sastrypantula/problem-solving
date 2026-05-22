class Solution {
public:
int n;
vector<int> dp;
int func(int i,int k,vector<int>& arr){
   if(i>=n){
    return 0;
   }
   if(dp[i]!=-1){
    return dp[i];
   }
    int ans=0;
    int maxi=INT_MIN;
    for(int j=i;j<i+k && j<n;j++){
      maxi=max(maxi,arr[j]);
      int temp=(j-i+1)*maxi+func(j+1,k,arr);
      ans=max(ans,temp);
    }
    return dp[i]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        dp.resize(n,-1);
        return func(0,k,arr);
    }
};