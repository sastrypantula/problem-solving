class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mymap;
        for(int it:nums){
             mymap[it]++;
            if(mymap[it]>=2){
                return true;
            }
           
        }
        return false;
    }
};