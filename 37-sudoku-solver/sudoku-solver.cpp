class Solution {
public:
int rows;
int cols;
bool chk(int i,int j,int k,vector<vector<char>>& board){
int col=0;
int row=0;
while(col<cols){
    if(board[i][col]==k+'0'){
        return false;
    }
    col++;
}
while(row<rows){
    if(board[row][j]==k+'0'){
        return false;
    }
    row++;
}
int start_row=3*(i/3);
int start_col=3*(j/3);
for(int r=start_row;r<start_row+3;r++){
    for(int c=start_col;c<start_col+3;c++){
if(board[r][c]==k+'0'){
    return false;
}
    }
}
return  true;
}
bool solve(vector<vector<char>>& board){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(board[i][j]=='.'){
                for(int k=1;k<=9;k++){
                    if(chk(i,j,k,board)){
                        board[i][j]=k+'0';
                       if(solve(board)==true){
                        return true;
                       }
                       else{
                        board[i][j]='.';
                       }
                    }
                    
                }
                return false;
            }
        }
    }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        rows=board.size();
        cols=board[0].size();
        solve(board);
    }
};