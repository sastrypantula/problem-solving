class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1) return nums;
        if(n==2){
            if(nums[0]%nums[1]==0 || nums[1]%nums[0]==0){
                return nums;
            }
            return {nums[0]};
        }
       vector<int> ind(n,-1);
       vector<int> dp(n,1);
       int maxlen=1;
       for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    ind[i]=j;
                    maxlen=max(maxlen,dp[i]);
                }
            }
        }
       } 
       vector<int>ans;
       int index=-1;
       for(int i=n-1;i>=0;i--){
           if(dp[i]==maxlen){
            index=i;
            break;
           }
       }
       while(ind[index]!=-1){
        ans.push_back(nums[index]);
        index=ind[index];
       }
       ans.push_back(nums[index]);
       reverse(ans.begin(),ans.end());
       return ans;
    }
};