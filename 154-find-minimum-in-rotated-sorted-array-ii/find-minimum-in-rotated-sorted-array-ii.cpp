class Solution {
public:
    int findMin(vector<int>& nums) {
          int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=INT_MAX;
        while(i<j && nums[i]==nums[i+1]) i++;
        while(j>i && nums[j]==nums[j-1]) j--;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]<=nums[i] && nums[mid]<=nums[j]){
                ans=min(ans,nums[mid]);
                j=mid-1;
            }
            else if(nums[mid]>=nums[i] && nums[mid]>nums[j]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};