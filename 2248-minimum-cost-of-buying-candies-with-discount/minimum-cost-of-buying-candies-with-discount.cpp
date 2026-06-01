class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int ans=0;
        sort(cost.begin(),cost.end());
  
        for(int i=n-1;i>=0;i--){
            if((n-i)%3!=0)
            ans=ans+cost[i];
           
        }
        return ans;
    }
};