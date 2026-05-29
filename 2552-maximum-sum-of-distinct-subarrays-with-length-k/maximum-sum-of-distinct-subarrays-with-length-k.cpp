class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,int> mymap;
        int n=nums.size();
        int i=0;
        int j=0;
        long long sum=0;
        while(j<n){
            mymap[nums[j]]++;
            sum=sum+nums[j];
            while(mymap[nums[j]]>1){
                sum=sum-nums[i];
                mymap[nums[i]]--;
                i++;
            }
            if(j-i+1==k){
                ans=max(ans,sum);
                sum=sum-nums[i];
                mymap[nums[i]]--;
                i++;
            }
            cout<<sum<<endl;
            j++;
        }
        return ans;
    }
};