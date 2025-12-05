class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n-1;i++){
            int a=prefix[i];
            int b=prefix[n-1]-a;
            if((b-a)%2==0){
                count++;
            }
        }
        return count;
    }
};