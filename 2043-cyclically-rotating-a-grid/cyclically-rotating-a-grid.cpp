class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int s=min(m,n);
        int d=s/2;
        vector<vector<int>> layers(d);
        int r=m;
        int c=n;
        for(int l=0;l<d;l++){
            vector<int> temp;
            int i=l;
            int j=l;
            while(j<c){
                temp.push_back(grid[i][j]);
                j++;
            }
            i++;
            j--;
            while(i<r){
                temp.push_back(grid[i][j]);
                i++;
            }
            i--;
            j--;
            while(j>=l){
                temp.push_back(grid[i][j]);
                j--;
            }
            j++;
            i--;
            while(i>=l){
                temp.push_back(grid[i][j]);
                i--;
            }
            r--;
            c--;
              temp.pop_back();
              layers[l]=temp;
        }
                  // print 
    //         for (int l = 0; l < layers.size(); l++) {
    //     for (int x : layers[l]) cout << x << " ";
    //     cout << endl;
    // }
        // now i am doing the rotation thing
        for(int i=0;i<layers.size();i++){
            vector<int>& temp=layers[i];
            int siz=temp.size();
            int kk=k;
            if(k>=siz){
             kk=k%(siz);
            }
            vector<int> res(siz,0);
            for(int j=0;j<siz;j++){
                int id=((j-kk)+siz)%siz;
                // cout<<id<<endl;
                res[id]=temp[j];
            }
            // for(int i=0;i<siz;i++){
            //     cout<<res[i]<<" ";
            // }
            layers[i]=res;
        }

        // now keeping the things in the array
         r=m;
         c=n;
        for(int l=0;l<d;l++){
            vector<int> temp;
            int sz=layers[l].size();
            int it=0;
            int i=l;
            int j=l;
            while(j<c){
                grid[i][j]=layers[l][it++];
                j++;
            }
            i++;
            j--;
            while(i<r){
                 grid[i][j]=layers[l][it++];
                i++;
            }
            i--;
            j--;
            while(j>=l){
             grid[i][j]=layers[l][it++];
                j--;
            }
            j++;
            i--;
            while(i>=l && it<sz){
                  grid[i][j]=layers[l][it];
                  it++;
                i--;
            }
            r--;
            c--;
            
        }
    return grid;
    }
};
