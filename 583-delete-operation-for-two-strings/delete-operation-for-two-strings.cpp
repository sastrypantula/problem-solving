class Solution {
public:
int lcs(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
 if(i<0 || j<0){
    return 0;
 }
 if(dp[i][j]!=-1){
    return dp[i][j];
 }
if(s1[i]==s2[j]){
   return dp[i][j]=1+lcs(s1,s2,i-1,j-1,dp);
}

    int exclude_s1=lcs(s1,s2,i-1,j,dp);
    int exclude_s2=lcs(s1,s2,i,j-1,dp);
    return dp[i][j]=max(exclude_s1,exclude_s2);


}
    int minDistance(string word1, string word2) {
        // see logic is simple find the longest common sunsequence and for both n1-lcs+n2-lcs
         int n1=word1.length();
         int n2=word2.length();
         vector<vector<int>> dp(n1,vector<int>(n2,-1));
        int n=lcs(word1,word2,n1-1,n2-1,dp);
        return (n1-n)+(n2-n);
    }
};