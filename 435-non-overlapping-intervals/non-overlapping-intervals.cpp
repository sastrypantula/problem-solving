class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int ans=0;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            vector<int> a=result.back();
            vector<int> b=intervals[i];
            if(a[1]<=b[0]){
                result.push_back(b);
            }
            else{
                ans++;
                int l=min(a[0],b[0]);
                int r=min(a[1],b[1]);
                result.pop_back();
                result.push_back({l,r});
            }
        }
return ans;
    }
};