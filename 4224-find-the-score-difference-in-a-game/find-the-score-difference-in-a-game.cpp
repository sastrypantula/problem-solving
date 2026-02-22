class Solution {
public:
    int scoreDifference(vector<int>& nums) {
         vector<int> temp(2,0);
         int k=0;
         int n=1;
        for(int i=0;i<nums.size();i++){
           if(nums[i]%2==1){
            k=(k+1)%2;
           }
           if((6*n-1)==i){
            n++;
                k=(k+1)%2;
           }
           temp[k]=temp[k]+nums[i];
        }
        return temp[0]-temp[1];
    }
};