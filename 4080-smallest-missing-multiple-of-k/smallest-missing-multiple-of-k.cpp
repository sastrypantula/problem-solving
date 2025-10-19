class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
 
        unordered_set<int>myset(nums.begin(),nums.end());
        int i=1;
        while(true){
          if(myset.find(i*k)==myset.end()){
            return i*k;
          }
          i++;
        }
        return -1;
    }
};