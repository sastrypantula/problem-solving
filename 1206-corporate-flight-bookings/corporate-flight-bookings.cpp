class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto it:bookings){
            int i=it[0];
            int j=it[1];
            int seats=it[2];
            ans[i-1]+=seats;
            if(j<n){
                ans[j]=ans[j]-seats;
            }
        }
        for(int i=0;i<n;i++){
            if(i>0){
                ans[i]=ans[i]+ans[i-1];
            }
        }
        return ans;
    }
};