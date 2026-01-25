class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==0 || k==1){
            return 0;
        }
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            if(j-i+1==k){
                ans=min(ans,nums[j]-nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};