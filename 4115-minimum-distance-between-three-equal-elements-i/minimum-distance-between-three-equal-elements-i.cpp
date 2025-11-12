class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int dist=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        int a=abs(i-j)+abs(j-k)+abs(k-i);
                        dist=min(dist,a);
                    }
                }
            }
        }
        if(dist==INT_MAX){
            return -1;
        }
        return dist;
    }
};