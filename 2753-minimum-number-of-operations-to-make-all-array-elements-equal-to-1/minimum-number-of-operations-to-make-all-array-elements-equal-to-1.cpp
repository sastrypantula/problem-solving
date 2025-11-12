class Solution {
public:
    int minOperations(vector<int>& nums) {
        int countOnes=0;
        for(int it:nums){
            if(it==1){
                countOnes++;
            }
        }
        int n=nums.size();
        if(countOnes>0){
            return n-countOnes;
        }
        int operations=INT_MAX;
     
        for(int i=0;i<n-1;i++){
            int gcd=nums[i];
            for(int j=i+1;j<n;j++){
                gcd=__gcd(gcd,nums[j]);
                if(gcd==1){
                    operations=min(operations,j-i);
                }
            }
        }
        if(operations==INT_MAX){
            return -1;
        }
        return operations+n-1;
    }
};