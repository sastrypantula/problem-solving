class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int ans=1;
        // int n=piles.size();
        // int maxi=*max_element(piles.begin(),piles.end());
        // int i=1;
    
        // while(i<=maxi){
        //     int temp=0;
        // for(int j=0;j<n;j++){
        //       temp=temp+(ceil((float)piles[j]/i));
        //       if(temp>h){
        //         break;
        //       }
        // }
        // if(temp<=h){
        //     ans=i;
        //     break;
        // }
        // i++;
        // }
        // return ans;
        int ans=INT_MAX;
        int n=piles.size();
        int low=1;
        int high=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            int temp=0;
           
            for(int i=0;i<n;i++){
                temp=temp+ceil((double)piles[i]/mid);
                if(temp>h){
                    break;
                }
            }
            if(temp<=h){
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