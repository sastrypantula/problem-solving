class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> result;
        int n=intervals.size();
         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });
    result.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        vector<int> a=result.back();
        vector<int> b=intervals[i];
        if(a[1]<b[0]){
            result.push_back(b);
            continue;
        }
        else{
            result.pop_back();
            int l=min(a[0],b[0]);
            int r=max(a[1],b[1]);
            result.push_back({l,r});
        }
    }
    return result;
    }
};