class Solution {
public:
int chk(int target, vector<pair<int,int>>& temp,int low,int high,vector<int>& arr){
     int position=-1;
    if(high<0){
        return position;
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(temp[mid].first<target){
          position=mid;
          low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return position;
}
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>> temp;
        int ans=INT_MIN;
        for(int i=0;i<costs.size();i++){
            temp.push_back({costs[i],capacity[i]});
            if(costs[i]<budget)
            ans=max(ans,capacity[i]);
        }
        sort(temp.begin(),temp.end());
        int n=costs.size();
        vector<int> arr(n,0);
        arr[0]=temp[0].second;
        for(int i=1;i<n;i++){
            arr[i]=max(arr[i-1],temp[i].second);
        }
        for(int i=0;i<n;i++){
            int t=budget-temp[i].first;
             int second_idx=chk(t,temp,0,i-1,arr);
             if(second_idx==-1){
                continue;
             }
             ans=max(ans,temp[i].second+arr[second_idx]);
        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};