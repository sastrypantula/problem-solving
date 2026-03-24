class Solution {
public:
const int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long pro=1;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> prefix(m,vector<long long>(n));
        vector<vector<long long>> suffix(m,vector<long long>(n));
        prefix[0][0]=1;
      
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                      pro=(pro*grid[i][j])%mod;
                    continue;
                }
                else{
                prefix[i][j]=pro;
                }
                pro=(pro*grid[i][j])%mod;
            }
        }
        // printing the prefix array 
        // cout<<"Prefix array values are: "<<endl;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<prefix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        pro=1;
        suffix[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    pro=(pro*grid[i][j])%mod;
                 continue;
                }
                else{
              suffix[i][j]=pro;
                }
                pro=(pro*grid[i][j])%mod;
            }
        }
        //   cout<<"suffix array values are: "<<endl;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<suffix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    
        vector<vector<int>> res(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j]=(prefix[i][j]*suffix[i][j])%mod;
            }
        }
        return res;
    }
};