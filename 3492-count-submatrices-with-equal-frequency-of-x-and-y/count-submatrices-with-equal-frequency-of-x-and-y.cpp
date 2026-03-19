class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int x=0;
        int y=0;
        int ans=0;
        for(int i=0;i<cols;i++){
            if(grid[0][i]=='X'){
                x++;
            }
            else if(grid[0][i]=='Y'){
                y++;
            }
            if(x==y && x>0){
                ans++;
            }
        }
        vector<vector<pair<int,int>>> mat(rows,vector<pair<int,int>>(cols,{0,0}));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i>0){
                   if(grid[i][j]=='X'){
                      mat[i][j].first=mat[i-1][j].first+1;
                      mat[i][j].second=mat[i-1][j].second;
                    }
                    else if(grid[i][j]=='Y'){
                        mat[i][j].second=mat[i-1][j].second+1;
                        mat[i][j].first=mat[i-1][j].first;
                    }
                    else{
                        mat[i][j]=mat[i-1][j];
                    }
                }
                else{
                    if(grid[i][j]=='X'){
                        mat[i][j].first++;
                    }
                    else if(grid[i][j]=='Y'){
                        mat[i][j].second++;
                    }
                }
            }
        }
        // cout<<ans<<endl;
    //     for(int i=0;i<rows;i++){
    //         for(int j=0;j<cols;j++){
    //             cout<<mat[i][j].first<<" "<<mat[i][j].second<<"----";
    //         }
    //    cout<<endl;
    //     }
        for(int i=1;i<rows;i++){
            x=0;
            y=0;
            for(int j=0;j<cols;j++){
                x=x+mat[i][j].first;
                y=y+mat[i][j].second;
                if(x==y && x>0){
                    ans++;
                }
            }
        }
        return ans;
    }
};