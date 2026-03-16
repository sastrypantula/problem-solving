class Solution {
public:
void func(int n,set<int>& myset){
      myset.insert(n);
    if(myset.size()>3){
        myset.erase(myset.begin());
    }
  
}
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        set<int> myset;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                func(grid[i][j],myset);
                // make this element as center and calculate all the diagonal elements sum 
                // center ---- i,j;
                // top---- i-side,j
                // right--- i,j+side
                // bottom --- i+side,j
                // left------ i,j-side
                for(int side=1;0<=i-side && i+side<m && 0<=j-side && j+side<n;side++){
                    int sum=0;
                      for(int k=0;k<side;k++){
                        sum=sum+grid[i-side+k][j+k]; // top to right
                        sum=sum+grid[i+k][j+side-k]; // right to bottom 
                        sum=sum+grid[i+side-k][j-k]; // bottom to left
                        sum=sum+grid[i-k][j-side+k]; // left to top

                      }
                      func(sum,myset);
                }
            }
        }
        vector<int> ans(myset.rbegin(),myset.rend());
        return ans;
    }
};