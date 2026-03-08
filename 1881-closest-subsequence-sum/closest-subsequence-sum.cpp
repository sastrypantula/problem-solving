class Solution {
public:
   void func(int i,int n,vector<int>& nums,vector<int>& temp,int sum){
     if(i>=n){
        temp.push_back(sum);
        return;
     }
    func(i+1,n,nums,temp,sum+nums[i]);
    func(i+1,n,nums,temp,sum);
   }
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> temp1;
        vector<int> temp2;
        int n=nums.size();
        int mid=n/2;
        func(0,mid,nums,temp1,0);
        func(mid,n,nums,temp2,0);
        int ans=INT_MAX;
        sort(temp2.begin(),temp2.end());
        for(int it:temp1){
            int x=it;
            int y=goal-x;
            int res=INT_MIN;

           int low=0;
         int high=temp2.size()-1;

while(low<=high){
    int mid=(low+high)/2;

    if(temp2[mid]<=y){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}


if(high>=0){
    ans=min(ans,abs(x+temp2[high]-goal));
}
if(low<temp2.size()){
    ans=min(ans,abs(x+temp2[low]-goal));
}
           

        }
        return ans;
    }
};