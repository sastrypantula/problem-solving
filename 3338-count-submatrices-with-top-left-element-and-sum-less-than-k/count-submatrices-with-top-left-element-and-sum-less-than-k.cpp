class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> temp(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0){
                    temp[i][j]=grid[i][j];
                }
                else{
                    temp[i][j]=temp[i-1][j]+grid[i][j];
                }
            }
        }
        int ans=0;
        int sum=0;
        for(int i=0;i<cols && sum+grid[0][i]<=k;i++){
            sum=sum+grid[0][i];
            ans++;
        }
        for(int i=1;i<rows;i++){
            sum=0;
            for(int j=0;j<cols && sum+temp[i][j]<=k;j++){
                sum=sum+temp[i][j];
                ans++;
            }
        }
        return ans;
    }
};