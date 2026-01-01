class Solution {
public:
int rows;
int cols;
bool func(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
 
        if (i < 0 || j < 0 || i >= rows || j >= cols) return false;   
        if (grid[i][j] == 1 || vis[i][j]) return false;
        if (i == rows - 1) return true;

        vis[i][j] = 1; 

   
        bool down  = func(i + 1, j, grid, vis);
        bool up    = func(i - 1, j, grid, vis);
        bool left  = func(i, j - 1, grid, vis);
        bool right = func(i, j + 1, grid, vis);

        return down || up || left || right;
}
bool check(vector<vector<int>>& grid){
     vector<vector<int>> vis(rows, vector<int>(cols, 0));
for(int i=0;i<cols;i++){


    if(grid[0][i]!=1){
        if(func(0,i,grid,vis)){
             return true;
        }
    }
}
return false;
}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=INT_MIN;
        int n=cells.size();
        rows=row;
        cols=col;
        vector<vector<int>> grid(row,vector<int>(col,0));
        int low=0;
        int high=n-1;
        while(low<=high){
         int mid=(low+high)/2;
         grid.assign(row,vector<int>(col,0));
         for(int i=0;i<=mid;i++){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;
            grid[r][c]=1;
         }
         if(check(grid)){
            ans=max(ans,mid);
            low=mid+1;
         }
         else{
            high=mid-1;
         }
        }
        if(ans!=INT_MIN){
            return ans+1;
        }
        return 1;
    }
};