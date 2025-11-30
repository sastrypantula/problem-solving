class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       long long sum=0;
       int n=nums.size();
       for(int it:nums){
        sum+=it;
       } 
       if(sum%p==0){
        return 0;
       }
       long long cumsum=0;
       int target=sum%p;
       unordered_map<int,int>mymap;
       mymap[0]=-1;
       int res=INT_MAX;
       for(int i=0;i<n;i++){
          cumsum=(cumsum+nums[i])%p;
           int t=(cumsum-target+p)%p;
           if(mymap.count(t)){
             res=min(res,i-mymap[t]);
           }
           mymap[cumsum]=i;
       }
       if(res==INT_MAX || res==n){
        return -1;
       }
       return res;
    }
};