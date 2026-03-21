class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m=grid.size();
        int n=grid[0].size();
        for(int col=y;col<y+k;col++){
            int i=x;
            int j=x+k-1;
            while(i<=j){
                int temp=grid[i][col];
                grid[i][col]=grid[j][col];
                grid[j][col]=temp;
                i++;
                j--;
            }
        }
        return grid;
    }
};