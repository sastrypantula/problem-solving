class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int sum=0;
        for(int it:nums){
            sum=sum+it;
        }
        sort(nums.begin(),nums.end());
        int temp=0;
        for(int i=n-1;i>=0;i--){
          temp=temp+nums[i];
          sum=sum-nums[i];
          ans.push_back(nums[i]);
          if(temp>sum){
            return ans;
          }
        }
        return ans;
    }
};