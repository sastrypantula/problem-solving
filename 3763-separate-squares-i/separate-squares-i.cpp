class Solution {
public:
    double areaBelow(double mid, vector<vector<int>>& squares) {
        double area = 0.0;
        for (auto &sq : squares) {
            double y = sq[1], len = sq[2];
            if (mid >= y + len) {
                area += len * len;
            } else if (mid > y) {
                area += len * (mid - y);
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        double ans=0.00000;
        double low=INT_MAX;
        double high=INT_MIN;
        double totalarea=0;
        for(auto it:squares){
        double x=it[0];
        double y=it[1];
        double len=it[2];
            low=min(low,y);
            high=max(high,y+len);
            totalarea=totalarea+len*len;
        }
        double target=totalarea/2;
           while (high - low > 1e-5) {
            double mid = (low + high) / 2.0;
            ans=mid;
            if(areaBelow(mid,squares)>=target){
                high=mid;
            }
            else{
               low=mid;
            }
        }
        return ans;
        
    }
};