class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=0;
       sort(time.begin(),time.end());
       int n=time.size();
        long long i=1;
        long long j=1LL*totalTrips*time[0];
     
         while(i<=j){
            long long mid=(i+j)/2;
               long long t=mid;
             int trips=0;
             bool flag=false;
            for(int i=0;i<time.size();i++){
                trips+=(t/time[i]);
                if(trips>=totalTrips){
                    ans=t;
                    flag=true;
                    break;
                }
            }
            if(flag){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        
         }
         return ans;
    }
};