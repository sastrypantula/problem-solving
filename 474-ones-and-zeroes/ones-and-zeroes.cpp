class Solution {
public:
int dp[601][101][101];
int func(vector<pair<int,int>>& res,int i,int m,int n){
    if(i==res.size()){
        return 0;
    }
    if(dp[i][m][n]!=-1){
        return dp[i][m][n];
    }
    int zeros=res[i].first;
    int ones=res[i].second;
    int skip=func(res,i+1,m,n);
    int take=0;
    if(zeros<=m && ones<=n){
        take=1+func(res,i+1,m-zeros,n-ones);
    }
    return dp[i][m][n]=max(take,skip);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
       vector<pair<int,int>> res;
       for(string t:strs){
        pair<int,int>temp={0,0};
        for(int i=0;i<t.length();i++){
            if(t[i]=='0'){
                temp.first++;
            }
            else{
                temp.second++;
            }
        }
        res.push_back(temp);
       }
       memset(dp,-1,sizeof(dp));
       cout<<sizeof(dp)<<endl;
       return func(res,0,m,n);
    }
};