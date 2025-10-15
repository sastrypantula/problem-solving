class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int curr=1;
        int res=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                curr++;
            }
            else{
                prev=curr;
                curr=1;
            }
            res=max(res,curr/2);
            res=max(res,min(prev,curr));
        }
        return res;
    }
};