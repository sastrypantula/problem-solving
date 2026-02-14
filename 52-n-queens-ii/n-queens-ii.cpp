class Solution {
public:
vector<vector<string>> ans;
bool chkDiagonal(int row,int col,vector<string>& board){
    int i=row;
    int j=col;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    while(i>=0 && j<board[0].length()){
            if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
    return true;
}
  void chk(int row,vector<string>& board,vector<bool>& chkColumn,int n){
    if(row>=n){
        ans.push_back(board);
        return;
    }
    for(int k=0;k<n;k++){
        if(chkDiagonal(row,k,board) && chkColumn[k]==false){
            chkColumn[k]=true;
            board[row][k]='Q';
            chk(row+1,board,chkColumn,n);
            board[row][k]='.';
            chkColumn[k]=false;
        }
    }
  }
    int totalNQueens(int n) {

        vector<bool> chkColumn(n,false);
        vector<string> board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }
        chk(0,board,chkColumn,n);
         return ans.size();
    }
};