class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      bool same=true;
      int st=nums[0];
      for(int it:nums){
        if(it!=st){
            same=false;
            break;
        }
      }
      if(nums.size()==1 || same){
        return 0;
      }  
      if(k==0){
        return *nums.rbegin()-*nums.begin();
      }
      nums[0]=nums[0]+k;
      int t=nums[0];
      int maxi=INT_MIN;
      for(int i=1;i<nums.size();i++){
          int x=t-nums[i];
          if(-k<=x && x<=k){
            maxi=max(maxi,t);
          }
          else{
            nums[i]=nums[i]-k;
            maxi=max(maxi,nums[i]);
          }
      }
      return maxi-t;
    }
};