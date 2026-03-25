class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        
        long long totalsum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
        
                totalsum+=grid[i][j];
            }
        }
      


        long long curr=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                curr=curr+grid[i][j];
            }
            if(curr==totalsum-curr)return true;
         }
        curr=0;
        for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            curr=curr+grid[i][j];
        }
        if(curr==totalsum-curr)return true;
        }
        return false;
    }
};