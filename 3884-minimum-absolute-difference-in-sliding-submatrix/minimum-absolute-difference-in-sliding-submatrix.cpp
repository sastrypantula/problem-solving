class Solution {
public:
int func(int a,int b,int k,vector<vector<int>>& grid){
    set<int> myset;
    for(int i=a;i<a+k;i++){
        for(int j=b;j<b+k;j++){
            myset.insert(grid[i][j]);
        }
    }
    if(myset.size()==1){
        return 0;
    }
    int mini=INT_MAX;
    for(auto it=myset.begin();it!=myset.end();it++){
        if(it!=myset.begin()){
            auto pit=prev(it);
            mini=min(mini,abs(*it-*pit));
        }
    }
    return mini;
}
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+k-1<m && j+k-1<n){
                    ans[i][j]=func(i,j,k,grid);
                }
            }
        }
        return ans;
    }
};