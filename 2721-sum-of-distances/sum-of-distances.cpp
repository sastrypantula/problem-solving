class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n,0);
        unordered_map<int,vector<long long>> mymap;
        for(int i=0;i<n;i++){
            mymap[nums[i]].push_back(i);
        }
        for(auto it:mymap){
            vector<long long>& temp=it.second;
            long long sum=0;
            for(long long t:temp){
                sum=sum+t;
            }
            long long leftsum=0;
            int m=temp.size();
            for(int i=0;i<m;i++){
                long long rightsum=sum-leftsum-temp[i];
                long long left=temp[i]*1LL*i-leftsum;
                long long right=rightsum-temp[i]*1LL*(m-i-1);
                ans[temp[i]]=left+right;
                leftsum+=temp[i];
            }
        }
return ans;
    }
};