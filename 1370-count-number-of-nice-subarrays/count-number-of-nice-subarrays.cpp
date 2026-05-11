class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                temp.push_back(i);
            }
        }
        if(temp.empty() || temp.size()<k){
            return 0;
        }
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        vector<int> prefix(n,0);
        for(int i=1;i<n;i++){
            if(nums[i-1]%2==0){
                prefix[i]=1;
            }
            prefix[i]+=prefix[i-1];
        }
        vector<int> suffix(n,0);
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]%2==0){
                suffix[i]=1;
            }
            suffix[i]+=suffix[i+1];
        }
        while(j<temp.size()){
            if(j-i+1==k){
                int a=prefix[temp[i]];
                if(i!=0){
                    a=prefix[temp[i]]-prefix[temp[i-1]];
                }
                int b=suffix[temp[j]];
                if(j+1<temp.size()){
                    b=suffix[temp[j]]-suffix[temp[j+1]];
                }
               ans=ans+a+b+(a*b)+1;
               i++;
            }
            j++;
        }
return ans;
    }
};