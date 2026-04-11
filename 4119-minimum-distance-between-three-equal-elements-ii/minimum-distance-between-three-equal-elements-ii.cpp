class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]].push_back(i);
        }
        int n=nums.size();
        int ans=INT_MAX;
        for(auto it:mymap){
            vector<int> temp=it.second;
            int n1=temp.size();
            if(temp.size()>=3){
               int i=0;
               int j=1;
               int res=0;
               while(j<n1){
                    res=res+abs(temp[i]-temp[j]);
                    if(j-i+1==3){
                         res=res+abs(temp[i+1]-temp[j]);
                         ans=min(ans,res);
                         res=res-abs(temp[i]-temp[j]);
                         res=res-abs(temp[i]-temp[i+1]);
                         i++;
                    }
                    j++;
               }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};