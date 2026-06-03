class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m=landStartTime.size();
        int n=waterStartTime.size();
        vector<pair<int,int>> land;
        vector<pair<int,int>> water;
       int ans=INT_MAX;
       int curr1=INT_MAX;
       for(int i=0;i<m;i++){
        curr1=min(curr1,landStartTime[i]+landDuration[i]);
       }
       for(int j=0;j<n;j++){
           int start=max(curr1,waterStartTime[j]);
           ans=min(ans,start+waterDuration[j]);
       }
       curr1=INT_MAX;
        for(int i=0;i<n;i++){
        curr1=min(curr1,waterStartTime[i]+waterDuration[i]);
       }
       for(int j=0;j<m;j++){
           int start=max(curr1,landStartTime[j]);
           ans=min(ans,start+landDuration[j]);
       }
       return ans;

    }
};