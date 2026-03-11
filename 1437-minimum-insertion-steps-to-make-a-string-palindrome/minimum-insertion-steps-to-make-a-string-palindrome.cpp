class Solution {
public:
int func(int i,int j,int n,string& s,vector<vector<int>>& dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left=1e9;
    int right=1e9;
    if(s[i]==s[j]){
        return dp[i][j]=func(i+1,j-1,n,s,dp);
    }
    if(s[i]!=s[j]){
       left=1+func(i,j-1,n,s,dp);
       right=1+func(i+1,j,n,s,dp);
    }
return dp[i][j]=min(left,right);
}
    int minInsertions(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<=j && s[i]==s[j]){
            i++;
            j--;
        }

       if(i==j){
        return 0;
       }
       int new_length=j-i+1;
       vector<vector<int>> dp(new_length+1,vector<int>(new_length+1,-1));
       return func(i,j,n,s,dp);
    }
};
