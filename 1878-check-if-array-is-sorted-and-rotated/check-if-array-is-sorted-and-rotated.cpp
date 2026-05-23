class Solution {
public:
    bool check(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                index=i;
            }
           
        }
        int temp=index;
        int left=(index-1+n)%n;
        while(nums[index]==nums[left] && left!=temp){
            index=left;
            left=(index-1+n)%n;
        }
        int j=(index+1)%n;
        int prev;
        while(j!=index){
            prev=(j-1+n)%n;
            if(nums[prev]>nums[j]){
                return false;
            }
            j=(j+1)%n;
        }
        return true;
    }
};