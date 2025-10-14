class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i=0;
        int j=i+k;
        int n=nums.size();
        
        bool flag=false;
        while(j<n){
            int count=0;
            while(count<k){
                if(j+1<n && nums[i]<nums[i+1] && nums[j]<nums[j+1]){
                    i++;
                    j++;
                    count++;
                }
                else{
                    break;
                }
            }
            if(count>=k-1){
                return true;
            }
            i++;
            j=i+k;
        }
        return false;
    }
};