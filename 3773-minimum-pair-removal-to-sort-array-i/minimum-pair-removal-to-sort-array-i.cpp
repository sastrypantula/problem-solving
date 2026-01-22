class Solution {
public:
int n;
bool chk(vector<int>& nums){
    for(int i=1;i<n;i++){
        if(nums[i-1]<=nums[i]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

    int minimumPairRemoval(vector<int>& nums) {
       int ans=0;
       int t1=-1;
       int t2=-1;
       int currsum=INT_MAX;
       n=nums.size();
       while(chk(nums)!=true){
         for(int i=1;i<n;i++){
            if(nums[i]+nums[i-1]<currsum){
                t1=i-1;
                currsum=nums[i]+nums[i-1];
            }
         }
            nums[t1] = currsum;
            for (int i = t1 + 1; i < n - 1; i++) {
                nums[i] = nums[i + 1];
            }

            n--;  
            ans++;
            currsum=INT_MAX;
       } 
       return ans;
    }
};