class Solution {
public:
int rows;
int cols;
vector<vector<int>> dp;
int func(int i,int j,vector<vector<int>>& matrix){
 
    if(i<0 || i>=rows || j<0 || j>=cols){
        return INT_MAX;
    }
    if(i==rows-1){
        return matrix[i][j];
    }
    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    int ans=INT_MAX;
    int downleft=INT_MAX;
    int down=INT_MAX;
    int downright=INT_MAX;
   
        int val1=func(i+1,j-1,matrix);
        if(val1!=INT_MAX){
            downleft=matrix[i][j]+val1;
        }
        int val2=func(i+1,j,matrix);
        if(val2!=INT_MAX){
            down=matrix[i][j]+val2;
        }
         int val3=func(i+1,j+1,matrix);
        if(val3!=INT_MAX){
            downright=matrix[i][j]+val3;
        }
      ans=min(ans,min({downleft,down,downright}));
    
    return dp[i][j]=ans;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        rows=matrix.size();
        cols=matrix[0].size();
        dp.resize(rows,vector<int>(cols,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<cols;i++){
            int temp=func(0,i,matrix);
            ans=min(ans,temp);
        }
        return ans;
    }
};