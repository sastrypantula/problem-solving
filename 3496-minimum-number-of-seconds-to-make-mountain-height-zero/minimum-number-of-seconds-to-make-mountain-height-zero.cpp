class Solution {
public:
bool check(long long max_time,vector<int>& workerTimes,int mountainHeight){
  long long h=0;
    // this h height all sums of worker heights >=moutainHeight then its possible to decrease ok 
    for(int i=0;i<workerTimes.size();i++){
        long long h1=1LL*(sqrt((2*max_time/workerTimes[i])+0.25))-0.5;
        h=h+h1;
        if(h>=mountainHeight){
            return true;
        }
    }
    if(h>=mountainHeight) return true;
    return false;
}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
       // its a binary search on answer minimise the maximumm on Time ;
       long long ans=INT_MAX;
       int maxi=INT_MIN;
       for(int it:workerTimes){
        maxi=max(maxi,it);
      }
       long long low=1;
       long long high=1LL*maxi*mountainHeight*(mountainHeight+1)/2;
       while(low<=high){
        long long mid=(low+high)/2;
        if(check(mid,workerTimes,mountainHeight)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return ans;
    }
};