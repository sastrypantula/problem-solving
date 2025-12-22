class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
     int ans=0;
     int rows=strs.size();
     int cols=strs[0].size();
     vector<bool> ChkSorted(rows,false);
     for(int col=0;col<cols;col++){
        bool del=false;
        for(int row=0;row<rows-1;row++){
            if(ChkSorted[row]==false && strs[row][col]>strs[row+1][col]){
                del=true;
                ChkSorted[row]=false;
                ans++;
                break;
            }
        }
        if(del==true){
            continue;
        }
        for(int r=0;r<rows-1;r++){
            ChkSorted[r]=ChkSorted[r] | (strs[r][col]<strs[r+1][col]);
        }
     }
     return ans;
    }
};

