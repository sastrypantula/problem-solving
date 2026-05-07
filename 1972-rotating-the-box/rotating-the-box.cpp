class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>> res(n,vector<char>(m,'.'));
        // doing transpose
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][i]=boxGrid[i][j];
            }
        }
        // doing reversing to get the 90 tilted
        for(int i=0;i<n;i++){
            reverse(res[i].begin(),res[i].end());
        }
    
        // doing the simulation
        for(int j=0;j<m;j++){
            int empty=n-1;
            for(int i=n-1;i>=0;i--){
                if(res[i][j]=='*'){
                    empty=i-1;
                }
                else if(res[i][j]=='#'){
                
                    res[i][j]='.';
                    res[empty][j]='#';
                    empty--;

                }
            }
        }
        return res;
    }
};