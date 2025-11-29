class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(sum<k){
            return sum;
        }
        if(sum%k==0){
            return 0;
        }
        // int i=0;
        // int num=0;
        // while(num<sum){
        //     i++;
        //     num=k*i;
            
        // }
        // num=k*(i-1);
        // return abs(num-sum);
        int t=sum%k;
        return t;
    }
};