class Solution {
public:
//  Approach 1 i worked but not passed 1 testcase.......
// int n;
// int  binsearch(vector<int>& nums,int i,int k){
//     int idx=i;
//     int high=n-1;
//     int low=i+1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(nums[mid]<=(long long)k*nums[i]){
//             idx=mid;
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return idx;
// }
    int minRemoval(vector<int>& nums, int k) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1){
            return 0;
        }
        if(n==2){
            if(nums[1]<=nums[0]*k){
                return 0;
            }
            else{
                return 1;
            }
        }
        // int i=n-1;
        // int mini=nums[0];
        // int maxi=nums[n-1];
        // int ans=INT_MAX;
        // int count=0;

        // if(maxi<=(long long)k*mini){
        //     return 0;
        // }
        // for(int i=0;i<n-1;i++){
        //     count=i;
        //     int idx=binsearch(nums,i,k);
        //     cout<<"For  idx: "<<idx<<" i is: "<<i<<endl;
        //     count=count+n-idx-1;
        //     ans=min(ans,count);
        // }
        
        // if(ans==INT_MAX){
        //     return n-1;
        // }
        // return ans;


        // Approach 2

        int i=0;
        int j=0;
        int ans=0; // It represents the longest balanced array means maxi<=k*mini
        while(j<n && i<n){
           if(nums[j]<=(long long)nums[i]*k){
            ans=max(ans,j-i+1);
            j++;
            
            continue;
           }
           else{
            while(i<=j && nums[j]>(long long)nums[i]*k){
                i++;
            }
          
           }
           j++;
        }
        return n-ans;// represents the minuimum number of deletions
    }
};