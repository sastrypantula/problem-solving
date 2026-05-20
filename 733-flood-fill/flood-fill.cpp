class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int rows=image.size();
        int cols=image[0].size();
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int n=q.size();
            while(n--){
               pair<int,int> p=q.front();
               q.pop();
               int i=p.first;
               int j=p.second;
               for(auto it:dirs){
                int x=i+it[0];
                int y=j+it[1];
                if(0<=x && x<rows && 0<=y && y<cols){
                    if(image[x][y]==prev && image[x][y]!=color){
                        image[x][y]=color;
                        q.push({x,y});
                    }
                }
               }
            }
        }
        return image;
    }
};