class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                result=result|nums[i];
            }
        }
        return result;
    }
};