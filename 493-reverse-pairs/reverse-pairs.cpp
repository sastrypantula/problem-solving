class Solution {
public:
void merge(int low,int mid,int high,vector<int>& nums){
    int n=high-low+1;
    vector<int> temp(n,0);
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]){
            temp[k]=nums[i];
            i++;
            k++;
        }
        else{
            temp[k]=nums[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=nums[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=nums[j];
        j++;
        k++;
    }
    int s=0;
    for(int r=low;r<=high;r++,s++){
        nums[r]=temp[s];
    }

}
int findcount(int low,int mid,int high,vector<int>& nums){
    int ans=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high &&
      (long long)nums[i] >
      2LL*nums[right]){
            right++;
        }
        ans=ans+(right-(mid+1));
    }
    return ans;
}
int mergesort(int low,int high,vector<int>& nums){
    if(low>=high){
        return 0;
    }
    int mid=(low+high)/2;
    int count1=mergesort(low,mid,nums);
    int count2=mergesort(mid+1,high,nums);
        int count3=findcount(low,mid,high,nums);
    merge(low,mid,high,nums);

    return count1+count2+count3;

}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
       return mergesort(0,n-1,nums);
    }
};