class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ans=0;
        int i=0;
        int j=0;
        map<int,int> mymap;
        int a,b;
        while(j<n){
            mymap[nums[j]]++;
             a=mymap.begin()->first;
             b=mymap.rbegin()->first;
            while(b-a>limit){
                mymap[nums[i]]--;
                if(mymap[nums[i]]==0){
                    mymap.erase(nums[i]);
                }
            a=mymap.begin()->first;
            b=mymap.rbegin()->first;
               i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
       
        return ans;
    }
};