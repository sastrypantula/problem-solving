class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        long long  profitsvalue=0;
        vector<long long>profit(n,0);
        for(int i=0;i<n;i++){
          profit[i]=prices[i]*strategy[i];
          profitsvalue+=profit[i];
        }
        int i=0;
        int j=0;
        long long maxgain=0;
        long long currentwindow=0;
        long long modifiedwindow=0;
        while(j<n){
            currentwindow+=profit[j];
            if(j-i+1>k/2){
                modifiedwindow+=prices[j];
            }
               if(j-i+1>k){
                currentwindow=currentwindow-profit[i];
                modifiedwindow=modifiedwindow-prices[i+k/2];
                i++;
            }
            if(j-i+1==k){
                maxgain=max(maxgain,(modifiedwindow-currentwindow));
            }
         
            j++;
        }
      
        return profitsvalue+maxgain;
    }
};