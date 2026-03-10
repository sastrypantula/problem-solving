class Solution {
public:
   int func(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
         if(i<0 || j<0){
            return 0;
         }
         if(dp[i][j]!=-1){
            return dp[i][j];
         }
         int result=0;
         if(s1[i]==s2[j]){
        result=1+func(s1,s2,i-1,j-1,dp);
         }
         else{
            result=max(func(s1,s2,i-1,j,dp),func(s1,s2,i,j-1,dp));
         }
         return dp[i][j]=result;
   }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string temp=s;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        reverse(temp.begin(),temp.end());
        return func(s,temp,n-1,n-1,dp);
    }
};