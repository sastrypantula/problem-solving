class Solution {
public:
int dp[100001][3];
int binsearch(vector<vector<int>>& events,int i){
    int low=i;
    int high=events.size()-1;
    int result=events.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(events[i][1]<events[mid][0]){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;
}
int solve(int i,vector<vector<int>>& events,int count){
    if(count==2 || i>=events.size()){
        return 0;
    }
    if(dp[i][count]!=-1){
        return dp[i][count];
    }
    int next_index=binsearch(events,i);
    int take=events[i][2]+solve(next_index,events,count+1);
    int skip=solve(i+1,events,count);
    return dp[i][count]=max(take,skip);
}
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        memset(dp,-1,sizeof(dp));
        int count=0;
        return solve(0,events,count);
    }
};