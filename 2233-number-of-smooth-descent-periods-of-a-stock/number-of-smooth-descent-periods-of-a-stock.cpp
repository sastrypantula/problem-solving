class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count=1;
        long long ans=1;
        for(int i=1;i<prices.size();i++){
          if(prices[i]+1==prices[i-1]){
            count++;
            ans=ans+count;
          }
          else{
            count=1;
            ans=ans+count;
          }
        }
          return ans;
    }
};