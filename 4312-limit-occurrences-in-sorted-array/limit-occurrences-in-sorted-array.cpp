class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        vector<int> ans;
        for(int it:nums){
            if(mymap[it]<k){
               ans.push_back(it);
            }
            mymap[it]++;
        }
        return ans;
    }
};