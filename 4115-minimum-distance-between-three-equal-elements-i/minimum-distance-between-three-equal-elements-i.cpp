class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-1;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i){
                        if(nums[i]==nums[j] && nums[j]==nums[k] && nums[k]==nums[i]){
                         ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                        }
                    }
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};