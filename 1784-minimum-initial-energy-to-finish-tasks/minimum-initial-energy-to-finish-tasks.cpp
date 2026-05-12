class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
     sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
    return (a[1] - a[0]) > (b[1] - b[0]); 
}); // more remaining more good for future 

        int mini=0;
        int maxi=0;
        for(auto it:tasks){
            mini=mini+min(it[0],it[1]);
            maxi=maxi+max(it[0],it[1]);
        }
      
        for(auto it:tasks){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        cout<<mini<<endl;
        cout<<maxi<<endl;
        int ans=INT_MAX;
        int n=tasks.size();
        while(mini<=maxi){
            int mid=(mini+maxi)/2;
            int t=mid;
            bool flag=true;
            for(int i=0;i<n;i++){
                if(t>=tasks[i][1]){
                    t=t-tasks[i][0];
                }
                else{
                    flag=false;
                }
            }
            if(flag){
                ans=min(ans,mid);
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
            cout<<"Mid BRo :"<<mid<<endl;
        }
        return ans;
    }
};