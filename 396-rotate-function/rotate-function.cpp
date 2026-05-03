// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//        int n=nums.size();
//        int prod=INT_MIN;
//        for(int i=0;i<n;i++){
//         int k=0;
//         int j=i;
//         int count=0;
//         int ans=0;
//         while(count<n){
//            ans=ans+(nums[j]*k);
//            k++;
//            j=(j+1)%n;
//             count++;
//         }
//         prod=max(prod,ans);
//        }  
//        return prod;
//     }
// };

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int sum=0;
       int n=nums.size();
         int prev=0;
       int next=0;
       for(int i=0;i<n;i++){
        sum=sum+nums[i];
        prev+=(i*nums[i]);

       }
     cout<<prev<<endl;
       int ans=prev;
       for(int i=1;i<n;i++){
        next=prev+sum-n*nums[n-i];
        cout<<next<<endl;
        ans=max(ans,next);
        prev=next;
       }
       return ans;
    }
};