class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int>mymap;
        for(int it:nums){
            mymap[it]++;
        }
        for(auto& [num,count]:mymap){
            if(count%k==0){
                res=res+(num*count);
            }
        }
        return res;
    }
};