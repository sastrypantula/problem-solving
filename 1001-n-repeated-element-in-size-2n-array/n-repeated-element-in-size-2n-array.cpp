class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n1=nums.size()/2;
        // unordered_map<int,int>mymap;
        // for(int it:nums){
        //     mymap[it]++;
        // }
        // for(auto [n,v]:mymap){
        //     if(v==n1){
        //         return n;
        //     }
        // }
        // return -1;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]==nums[j]){
                int count=1;
                while(j<nums.size() && nums[i]==nums[j]){
                    count++;
                    j++;
                }
              if(count==n1){
                return nums[i];
              }
            }
            i++;
            j++;
        }
return -1;
    }
};