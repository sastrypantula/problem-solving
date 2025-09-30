class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp=nums;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>result;
        while(temp.size()){
            for(int i=0;i<temp.size()-1;i++){
             result.push_back((temp[i]+temp[i+1])%10);
            }
            temp=result;
            result.clear();
            n--;
        }
        return result[0];
    }
};