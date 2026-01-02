class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n1=nums.size()/2;
        unordered_map<int,int>mymap;
        for(int it:nums){
            mymap[it]++;
        }
        for(auto [n,v]:mymap){
            if(v==n1){
                return n;
            }
        }
        return -1;

    }
};