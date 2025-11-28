class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mymap;
        for(int i=0;i<n;i++){
            if(mymap.count(nums[i])==0){
                mymap[nums[i]]=i;
            }
            else{
                if(abs(mymap[nums[i]]-i)<=k){
                    return true;
                }
                else{
                    mymap[nums[i]]=i;
                }
            }
        }
        return false;
    }
};