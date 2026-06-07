class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
       int l=max(0,n-k);
       int r=n+k;
       int ans=0;
       for(int i=l;i<=r;i++){
        if((i&n)==0){
          ans=ans+i;
        }
       } 
       return ans;
    }
};