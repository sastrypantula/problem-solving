class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3){
            return nums[2]*nums[1]*nums[0];
        }
        int n=nums.size();
        int res=1;
        int count=0;
        sort(nums.begin(),nums.end());
        bool pos=true;
        bool neg=true;
        bool zero=true;
        for(int it:nums){
            if(it>0){
                neg=false;
                zero=false;
            }
            else if(it<0){
                pos=false;
                zero=false;
            }
          
            }
cout<<"Positive : "<<pos<<endl;
cout<<"Negative : "<<neg<<endl;
cout<<"Zero : "<<zero<<endl;
        if(neg==false && pos==true){
              return nums[n-1]*nums[n-2]*nums[n-3];
        }
        if(neg==true && pos==false){
              return nums[n-1]*nums[n-2]*nums[n-3];
        }
        int a=nums[0]*nums[1]*nums[n-1];
        int b=nums[n-1]*nums[n-2]*nums[n-3];
        return max(a,b);
    }
};