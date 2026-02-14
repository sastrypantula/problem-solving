class Solution {
public:
   vector<vector<string>> ans;
   bool chkDiagonal(vector<string>& board,int row,int col){

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
    void chk(int row,int n, vector<bool>& chkColumn,vector<string>& board){
       if(row>=n){
        ans.push_back(board);
        return;
       }

        for(int k=0;k<n;k++){
            if(chkDiagonal(board,row,k) && chkColumn[k]==false){
                board[row][k]='Q';
                chkColumn[k]=true;
                chk(row+1,n,chkColumn,board);
                board[row][k]='.';
                chkColumn[k]=false;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }
        vector<bool> chkColumn(n,false);
        chk(0,n,chkColumn,board);
        return ans;
    }
};