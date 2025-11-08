class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xz=0;
        int yz=0;
        int count=0;
        int n=grid.size();
           vector<int>cols(n,INT_MIN);
        for(int i=0;i<n;i++){
            int mini=INT_MIN;
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    count++;
                }
                mini=max(mini,grid[i][j]);
                cols[j]=max(cols[j],grid[i][j]);
            }
            xz+=mini;
        }
          for(int i=0;i<n;i++){
          yz+=cols[i];
          }
        return xz+yz+count;
    }
};