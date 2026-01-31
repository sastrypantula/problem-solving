class Solution {
public:
int  n;
   void find_subsets(vector<int>& nums,vector<int>& temp,vector<vector<int>>& result,int i){
     if(i>=nums.size()){
        result.push_back(temp);
        return;
     }
     temp.push_back(nums[i]);
     find_subsets(nums,temp,result,i+1);
      temp.pop_back();
      while(i+1<n && nums[i]==nums[i+1]){
        i++;
      }
     find_subsets(nums,temp,result,i+1);
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<vector<int>> result;
        vector<int> temp;
        n=nums.size();
        sort(nums.begin(),nums.end());
        find_subsets(nums,temp,result,0);
        return result;
    }
};