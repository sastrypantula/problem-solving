class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
         map<int,int> mymap;
         for(int it:nums){
            mymap[it]++;
         }
         int ans=0;
         int res=0;
         long long prev=-1e10;
         for(auto it:mymap){
            long long key=it.first;
            int val=it.second;
            if(prev==-1e10){
                res++;
                prev=key;
            }
            else if(key==prev+1){
                res++;
                prev=key;
            }
            else{
                ans=max(ans,res);
                res=1;
                prev=key;
            }

         }
         ans=max(ans,res);
         return ans;
    }
};