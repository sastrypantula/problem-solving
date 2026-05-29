class Solution {
public:
    int minOperations(vector<int>& nums) {
        int index=-1;
        int maxindex=-1;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        if(temp==nums){
            return 0;
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                index=i;
            }
            if(nums[i]==n-1){
                maxindex=i;
            }
        }
        int k=1;
        int j=(index-1+n)%n;
        bool left=true;
        while(j!=index){
            if(nums[j]!=k){
                left=false;
                break;
            }
            k++;
            j=(j-1+n)%n;
        }
        bool right=true;
        j=(index+1)%n;
        k=1;
        while(j!=index){
            if(nums[j]!=k){
                 right=false;
                 break;
            }
            k++;
            j=(j+1)%n;
        }
        if(left==false && right==false){
            return -1;
        }
        if(nums[0]==0 && nums[n-1]==n-1){
            return 0;
        }
        if(nums[0]==n-1 && nums[n-1]==0){
            return 1;
        }
        int mid=n/2;
        cout<<mid<<endl;
        cout<<"index "<<index<<endl;
        cout<<"maxindex "<<maxindex<<endl;
        int rev=n-maxindex-1;
        return min(maxindex+1,rev+1+1);
    }
};