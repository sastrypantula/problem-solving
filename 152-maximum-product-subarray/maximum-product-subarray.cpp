class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]);
        }
        int curr=1;
        int ele=INT_MIN;
        for(int i=0;i<n;i++){
            curr=curr*nums[i];
              ans=max(ans,curr);
            if(ele!=INT_MIN && curr<0){
                ans=max(ans,curr/ele);
            }
            if(curr<0){
                ele=max(ele,curr);
            }
            if(curr==0){
                curr=1;
                ele=INT_MIN;
            }
          
          
        }
        return ans;
    }
};