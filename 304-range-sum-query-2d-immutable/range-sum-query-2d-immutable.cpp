class NumMatrix {
public:
vector<vector<int>> grid;
int rows;
int cols;
vector<vector<int>> formula;
// formula is like A[2][2] = A[1][2]+A[2][1]-A[1][1]+arr[2-1][2-1];
    NumMatrix(vector<vector<int>>& matrix) {
        grid=matrix;
        rows=grid.size();
        cols=grid[0].size();
      formula.resize(rows+1,vector<int>(cols+1,0));
      for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            formula[i][j]=formula[i-1][j]+formula[i][j-1]-formula[i-1][j-1]+grid[i-1][j-1];
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (formula[row2+1][col2+1]-formula[row1][col2+1]-formula[row2+1][col1]+formula[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */