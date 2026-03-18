class Solution {
public:
bool chk(int j,string& p){
    while(j>=0){
        if(p[j]!='*'){
            return false;
        }
        j--;
    }
    return true;
}
bool func(int i,int j,string& s,string& p, vector<vector<int>>& dp){
   
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        if(chk(j,p)){
            return true;
        }
        return false;
    }
    if(i>=0 && j<0){
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==p[j] || p[j]=='?'){
          return dp[i][j]=func(i-1,j-1,s,p,dp);
    }
    else if(p[j]=='*'){
        return dp[i][j]=func(i-1,j,s,p,dp) || func(i,j-1,s,p,dp);
    }
    return dp[i][j]=false;
}
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,s,p,dp);
    }
};