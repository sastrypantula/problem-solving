class Solution {
public:
    int totalMoney(int n) {
        int res=0;
        int ans=0;
        int mon=0;
        int count=1;
        while(count<=n){
           if((count-1)%7==0){
            res=mon+1;
            mon++;
           }
           else{
            res=res+1;
           }
           ans=ans+res;
           cout<<res<<" ";
           count++;
        }
        return ans;
    }
};