class Solution {
public:
    int smallestNumber(int n) {
        // vector<int>res;
        // res.push_back(1);
        // for(int i=2;res.back()<=1000;i++){
        //     res.push_back(pow(2,i)-1);
        // }
        // cout<<res.back()<<endl;
        // int low=0;
        // int high=res.size()-1;
        // cout<<res.size()<<endl;
        // int mid;
        // while(low<high){
        //  mid=(low+high)/2;
        //     cout<<res[mid]<<" ";
        //     if(res[mid]<=n){
        //         low=mid+1;
        //     }
        //     else{
        //         high=mid-1;
        //     }
        // }
        // return res[low];

        bool flag=true;
        int temp=n;
        int i=0;
        int res=0;
        while(temp>0){
             int bin=temp%2;
             if(bin!=1){
                flag=false;
             }
             res=res+pow(2,i);
             i++;
             temp=temp/2;
        }
        if(flag){
        return pow(2,i)-1;
        }
        return res;
    }
};