class Solution {
public:
int rows;
int cols;
int n;
bool chk(int row,int col,vector<vector<char>>& board, string& word,int k){
if(k==n){
    return true;
}
if(row<0 || col<0 || row>=rows || col>=cols){
    return false;
}
if(board[row][col]!=word[k]){
    return false;
}

char temp=board[row][col];
board[row][col]='#';// this is very important for not visiting this cell again ok dryrun it


bool up=chk(row-1,col,board,word,k+1);
bool down=chk(row+1,col,board,word,k+1);
bool left=chk(row,col-1,board,word,k+1);
bool right=chk(row,col+1,board,word,k+1);

board[row][col]=temp;

if(up || down || left || right){
    return true;
}
return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        n=word.length();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(chk(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};