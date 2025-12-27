class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mymap;
        int  sum=0;
        for(int it:nums){
            sum=sum+it;
            mymap[it]++;
        }
        int ans=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            int t=sum-nums[i];
            mymap[nums[i]]--;
            if(t%2==0){
               int sp=t/2;
               if(mymap[sp]>0){
                ans=max(ans,nums[i]);
               }
            }
            mymap[nums[i]]++;
        }
        return ans;
    }
};