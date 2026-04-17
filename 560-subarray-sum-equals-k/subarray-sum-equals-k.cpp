class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        int count=0;
        unordered_map<int,int> mymap;
        for(int it:nums){
            sum=sum+it;
            if(sum==k){
                count++;
            }
            if(mymap.count(sum-k)){
                count=count+mymap[sum-k];
            }
            mymap[sum]++;
        }
        return count;
    }
};