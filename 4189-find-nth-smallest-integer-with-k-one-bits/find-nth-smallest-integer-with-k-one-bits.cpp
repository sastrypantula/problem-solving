// seen the solution and did the question but understood it 
class Solution {
public:
long long ncr(int n,int r){
    if(r>n){
        return 0;
    }
    if(r==0 || r==n){
        return 1;
    }
    long long res=1;
   for (int i = 1; i <= r; i++) {
     res = res * (n - i + 1) / i;
        }
        return res;

}
    long long nthSmallest(long long n, int k) {
        long long result=0;
        for(int bit=49;bit>=0;bit--){
            if(k==0){
                break;
            }
            long long count=ncr(bit,k);
            if(n>count){
               result=result|(1LL<<bit);
               n=n-count;
               k--;
            }
        }
        return result;
    }
};