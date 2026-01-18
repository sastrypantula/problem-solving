class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<vector<int>> temp;
        int x=center[0];
        int y=center[1];
        for(auto &tower:towers){
            int a=tower[0];
            int b=tower[1];
            int c=tower[2];
          int t=abs(x-a)+abs(y-b);
          if(t<=radius){
            temp.push_back({a,b,c});
          }
        }
        if(temp.size()==0){
            return {-1,-1};
        }

        sort(temp.begin(), temp.end(), [](const vector<int>& a,const vector<int>& b){
    if(a[2]!=b[2]) return a[2] > b[2];   
    if(a[0]!=b[0]) return a[0] < b[0];  
    return a[1] < b[1];  
        });                
vector<int> res = temp.front(); 

        vector<int> ans;
        ans.push_back(res[0]);
        ans.push_back(res[1]);
        return ans;
    }
};