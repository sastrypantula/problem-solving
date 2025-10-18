class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int n=nums.size();
        // bool zero=true;
        // bool neg=true;
        // for(int i=0;i<n;i++){
        //     nums.push_back(nums[i]);
        //     if(nums[i]>0){
        //         neg=false;
        //     }
        //     if(nums[i]!=0){
        //         zero=false;
        //     }
        // }
        // if(zero){
        //     return 0;
        // }
        // if(neg){
        //     sort(nums.begin(),nums.end());
        //     return nums.back();
        // }
        // int res=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int curr=0;
        //     for(int j=i;j<i+n;j++){
        //        curr+=nums[j];
        //        res=max(res,curr);
        //     }
           
        // }
        // return res;

          int maxi = nums[0],mini = nums[0],currmaxi = nums[0],currmini = nums[0],tot = nums[0];
        for(int i=1;i<nums.size();i++){
            currmaxi = max(currmaxi+nums[i],nums[i]);
            maxi = max(maxi,currmaxi);
            
            currmini = min(currmini+nums[i],nums[i]);
            mini = min(mini,currmini);
            
            tot += nums[i];
        }
        
        int circularSum = tot-mini;
        
        if(circularSum==0)
            return maxi;
        
        return max(maxi, circularSum);
    }
};