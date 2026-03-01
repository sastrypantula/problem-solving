class Solution {
public:
//    int func(int a,int b){
//     if(b==1){
//         return 1;
//     }
//     int left=a;
//     int right=func(1,n-1);
//    }
    int minCost(int n) {
        int ans=0;
        for(int i=1;i<n;i++){
            ans=ans+i;
        }
        return ans;
    }
};