class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        if(n==1){
            return 0;
        }
        vector<int> temp(n,0);
        temp[n-1]=INT_MIN;
        int maxi=INT_MIN;
        for(int i=n-2;i>=0;i--){
            maxi=max(prices[i+1],temp[i+1]);
            temp[i]=maxi;
        }
        // for(int i=0;i<n;i++){
        //     cout<<temp[i]<<" ";
        // }

        for(int i=0;i<n-1;i++){
            ans=max(ans,temp[i]-prices[i]);
        }
        return ans;
    }
};