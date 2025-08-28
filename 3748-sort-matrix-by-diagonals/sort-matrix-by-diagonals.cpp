class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,multiset<int>>mymap;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mymap[i-j].insert(grid[i][j]);
            }
        }
        int temp;
        vector<vector<int>> result(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int key=i-j;
                if(i<j){
                  auto it = mymap[key].begin();
                     temp = *it;
                    mymap[key].erase(it); 
                    result[i][j] = temp;

                }
                else{
                     auto it = prev(mymap[key].end());
                     temp = *it;
                    mymap[key].erase(it); 
                    result[i][j] = temp;

                }
                cout<<temp<<endl;
            }
        }
        return result;
    }
};