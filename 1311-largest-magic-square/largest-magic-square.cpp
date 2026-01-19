class Solution {
public:
int rows;
int cols;
int chk(int i, int j, vector<vector<int>>& grid) {
    int maxK = min(rows - i, cols - j);
    int best = 1;
    for (int k = 2; k <= maxK; k++) {
        int target = 0;
        bool valid = true;
        for (int c = j; c < j + k; c++){
        target += grid[i][c];
        }

        for (int r = i; r < i + k; r++) {
            int sum = 0;
            for (int c = j; c < j + k; c++) {
                sum += grid[r][c];
            }
            if (sum != target) {
                 valid = false; break; 
                 }
        }

        if (valid) {
            for (int c = j; c < j + k; c++) {
                int sum = 0;
                for (int r = i; r < i + k; r++){
                sum += grid[r][c];
                } 
                if (sum != target) { 
                    valid = false;
                     break;
                     }
            }
        }

      
        if (valid) {
            int d1 = 0, d2 = 0;
            for (int t = 0; t < k; t++) {
                d1 += grid[i + t][j + t];
                d2 += grid[i + t][j + k - 1 - t];
            }
            if (d1 != target || d2 != target) {
                valid = false;
            }
        }

        if (valid){
        best = k;
        }
    }
    return best;
}
    int largestMagicSquare(vector<vector<int>>& grid) {
        int k=0;
         rows=grid.size();
         cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                k=max(chk(i,j,grid),k);
            }
        }
        return k;
    }
};