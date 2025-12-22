class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dist=abs(rCenter-i)+abs(cCenter-j);
                ans.push_back({dist,i,j});
                }
        }
        sort(ans.begin(),ans.end(),[](const vector<int>&a , const vector<int>& b){
          
            return a[0]<b[0];
        });
        vector<vector<int>>result;
        for(auto& it:ans){
            result.push_back({it[1],it[2]});
        }
        return result;
    }
};