// LIS ki best example ee prblm so revise the bottom up approach before doing this 
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       int rows=strs.size();
       int cols=strs[0].size();
       vector<int>dp(cols,1);
       for(int i=0;i<cols;i++){
         for(int j=0;j<i;j++){
            bool valid=true;
            // now i check for all rows
            for(int k=0;k<rows;k++){
                if(strs[k][j]>strs[k][i]){
                    valid=false;
                    break;
                }
            }
            if(valid==true){
                dp[i]=max(dp[i],dp[j]+1);
            }
         }
       }
       int lis=1;
       for(int i=0;i<cols;i++){
        lis=max(lis,dp[i]);
       }
      int deletion_required=cols-lis;
      return deletion_required;
    }
};