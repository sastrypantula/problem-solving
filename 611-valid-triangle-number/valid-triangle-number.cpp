class Solution {
public:
int binsearch(vector<int>& nums,int sum,int low,int high){

    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]<sum){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;

}
    int triangleNumber(vector<int>& nums) {
         int n=nums.size();
         int count=0;
        //  for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]>nums[k] && nums[i]+nums[k]>nums[j] && nums[k]+nums[j]>nums[i]){
        //                 count++;
        //             }
        //         }
        //     }
        //  }

        ///....... BINARYSEARCH + SORTING................O(n^2 * log n)
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n-2;i++){
        //     for(int j=i+1;j<n-1;j++){
        //         int sum=nums[i]+nums[j];
        //        int ans= binsearch(nums,sum,j+1,n-1);
        //         count+=ans-j-1;
        //     }
        // }
        /////// Two pointer O(nsq)
        if(n<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int k=n-1;k>=2;k--){
            int j=k-1;
            int i=0;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+=j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }

         return count;
    }
};