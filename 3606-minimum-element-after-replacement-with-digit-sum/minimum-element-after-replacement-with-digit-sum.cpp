class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int t=nums[i];
            int sum=0;
            while(t>0){
                sum=sum+(t%10);
                t=t/10;
            }
           ans=min(ans,sum);
        }
        return ans;
    }
};