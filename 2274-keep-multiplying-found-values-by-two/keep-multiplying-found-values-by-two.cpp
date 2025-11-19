class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int ans=original;
        unordered_set<int>myset(nums.begin(),nums.end());
        while(myset.find(ans)!=myset.end()){
            ans=ans*2;
        }
        return ans;
    }
};