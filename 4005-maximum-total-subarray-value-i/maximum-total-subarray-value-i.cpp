class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long result=0;
        int n=nums.size();
        long long maxi=LONG_MIN;
        long long mini=LONG_MAX;
        for(int i=0;i<n;i++){
              if(nums[i]>maxi){
                maxi=nums[i];
              }
              if(nums[i]<mini){
                mini=nums[i];
              }
        }
        return (maxi-mini)*k;
    }
};