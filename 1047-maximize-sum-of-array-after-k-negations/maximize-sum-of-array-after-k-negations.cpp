class Solution {
public:

void func(vector<int>& nums,int k){
    int i=0;
    while(k>0 && i<nums.size()){
      
            if(nums[i]<0){
                nums[i]=nums[i]*-1;
                k--;
            }
        i++;
    }
}
int cal(vector<int>& nums){
int sum=0;
for(int it:nums){
    sum=sum+it;
}
return sum;
}
    int largestSumAfterKNegations(vector<int>& nums, int k) {
   sort(nums.begin(),nums.end());
   int cnt=0;
   for(int it:nums){
    if(it<0){
        cnt++;
    }
   }
    if(cnt==0 && k%2==0){
        return cal(nums);
    }
    if(cnt==0 && k%2==1){
        nums[0]=nums[0]*-1;
        // cout<<nums[0]<<endl;
        return cal(nums);
    }
    if(cnt>=k){
        func(nums,k);
        for(int it:nums){
            cout<<it<<" ";
        }
        return cal(nums);
    }
    if(cnt<k){
        int t=k-cnt;
        func(nums,cnt);
         for(int it:nums){
            cout<<it<<" ";
        }
        sort(nums.begin(),nums.end());
        if(t%2==1){
            nums[0]=nums[0]*-1;
        }
        return cal(nums);
    }
    return -1;


    }
};