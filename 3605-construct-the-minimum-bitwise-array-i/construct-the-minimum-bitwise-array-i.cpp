class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            bool flag=false;
            for(int t=1;t<=n-1;t++){
                if((t|(t+1))==n){
                    ans.push_back(t);
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};