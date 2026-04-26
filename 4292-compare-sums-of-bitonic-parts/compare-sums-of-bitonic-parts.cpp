class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum1=0;
        long long sum2=0;
        bool flag=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                sum1+=nums[i];
            }
            else{
                if(flag==false){
                    sum1+=nums[i];
                    flag=true;
                }
                sum2+=nums[i];
            }
        }
        sum2+=nums[nums.size()-1];
        cout<<sum1<<" "<<sum2<<endl;
        if(sum1>sum2) return 0;
        if(sum1<sum2) return 1;
        return -1;
    }
};