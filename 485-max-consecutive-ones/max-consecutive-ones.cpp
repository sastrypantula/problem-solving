class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                temp++;
            }
            else{
                size=max(size,temp);
                temp=0;
            }
        }
        return max(size,temp);
    }
};