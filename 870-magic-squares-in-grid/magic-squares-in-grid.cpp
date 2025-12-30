class Solution {
public:

bool check(int i,int j,vector<vector<int>>& grid){
    cout<<"Entered the check for "<<i<<" "<<j<<endl;
    unordered_set<int> myset;
    int a=grid[i][j];
    int b=grid[i+1][j+1];
    int c=grid[i+2][j+2];

    int d=grid[i][j+2];
    int f=grid[i+2][j];

    int k;
    int z;

    if(a!=b && b!=c && c!=a && 0<a && a<10 && 0<b && b<10 && 0<c &&  c<10 && d!=b && b!=f && f!=d && 0<d && d<10 && 0<f && f<10 && a!=d && a!=f && c!=d && c!=f){
  k=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
  z=d+b+f;
  if(k!=z){
    return false;
  }

    }
    else{
        return false;
    }
   
   
    for(int s=i;s<i+3;s++){
        int sum=0;
        for(int r=j;r<j+3;r++){
            if(myset.find(grid[s][r])==myset.end() && 0<grid[s][r] && grid[s][r]<10){
            sum=sum+grid[s][r];
            myset.insert(grid[s][r]);
            }
            else{
                cout<<"Entered the check1"<<endl;
                return false;
            }
        }
        if(sum!=k){
             cout<<"Entered the check2"<<endl;
            return false;
        }
    }
    for(int r=j;r<j+3;r++){
        int sum=0;
        for(int s=i;s<i+3;s++){
          sum=sum+grid[s][r];
        }
        if(sum!=k){
             cout<<"Entered the check4"<<endl;
            return false;
        }
    }
    for(int it:myset){
        cout<<it<<" ";
    }
    cout<<endl;


    return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        int rows=grid.size();
        int cols=grid[0].size();
        int lr=rows-3;
        int lc=cols-3;
        for(int i=0;i<=lr;i++){
            for(int j=0;j<=lc;j++){ 
                cout<<"OUT for "<<i<<" "<<j<<endl;
                if(check(i,j,grid)){
                    cout<<"IN for "<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};