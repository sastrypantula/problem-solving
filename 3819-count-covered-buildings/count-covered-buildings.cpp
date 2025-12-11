class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>>MinMaxY;// for X i am storing
        unordered_map<int,pair<int,int>>MinMaxX;// for y i am storing
        for(int i=0;i<buildings.size();i++){
            int x=buildings[i][0];
            int y=buildings[i][1];
            // for x stroing min max y
            if(MinMaxY.find(x)==MinMaxY.end()){
                pair<int,int> t=make_pair(y,y);
                MinMaxY[x]=t;
            }
            else{
                pair<int,int>t=MinMaxY[x];
                t.first=min(t.first,y);
                t.second=max(t.second,y);
                MinMaxY[x]=t;
            }
             // for y stroing min max x
            if(MinMaxX.find(y)==MinMaxX.end()){
                pair<int,int> t=make_pair(x,x);
                MinMaxX[y]=t;
            }
            else{
                pair<int,int>t=MinMaxX[y];
                t.first=min(t.first,x);
                t.second=max(t.second,x);
                MinMaxX[y]=t;
            }
        }
        int ans=0;
        for(int i=0;i<buildings.size();i++){
            //check for x and y;
            int x=buildings[i][0];
            int y=buildings[i][1];
            if(MinMaxY.count(x)>0 && MinMaxX.count(y)>0){
                pair<int,int>t=MinMaxY[x];
                pair<int,int>z=MinMaxX[y];
                if(t.first<y && y<t.second && z.first<x && x<z.second){
                    ans++;
                }
            }
        }
        return ans;
    }
};