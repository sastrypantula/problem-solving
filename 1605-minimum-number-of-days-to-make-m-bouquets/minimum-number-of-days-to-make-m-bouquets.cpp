class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=INT_MAX;
        int n=bloomDay.size();
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            int temp=0;
            int curr=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    temp++;
                }
                if(bloomDay[i]>mid){
                    temp=0;
                }
                if(temp==k){
                    curr++;
                    temp=0;
                }
              
            }
            if(curr>=m){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};