class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans=0;
        int n=bottomLeft.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1=topRight[i][0];
                int y1=topRight[i][1];
                int x2=topRight[j][0];
                int y2=topRight[j][1];
                int x3=bottomLeft[i][0];
                int y3=bottomLeft[i][1];
                int x4=bottomLeft[j][0];
                int y4=bottomLeft[j][1];
                int square_top_x=min(x1,x2);
                int square_top_y=min(y1,y2);
                int square_bottom_x=max(x3,x4);
                int square_bottom_y=max(y3,y4);
                int length=square_top_x-square_bottom_x;
                if(length<=0){
                    continue;
                }
                int breadth=square_top_y-square_bottom_y;
                if(breadth<=0){
                    continue;
                }
                long long side=min(length,breadth);
                long long area=side*side;
                // cout<<"Top right coordinates : "<<square_top_x<<","<<square_top_y<<endl;
                // cout<<"bottom left coordinates : "<<square_bottom_x<<","<<square_bottom_y<<endl;
                // cout<<area<<" for i="<<i<<" and j="<<j<<endl;

                ans=max(ans,area);
            }
        }
        return ans;
    }
};