class Solution {
public:
const int mod=1e9+7;
bool isprime(int t){
    if(t<=1){
        return false;
    }
    for(int i=2;i<t;i++){
        if(t%i==0){
            return false;
        }
    }
    return true;
}
long long fact(long long i){
    long long prod=1;
    for(long long p=1;p<=i;p++){
        prod=(1LL*prod*p)%mod;
    }
    return prod;
}
    int numPrimeArrangements(int n) {
        int count=0;
        for(int i=2;i<=n;i++){
            if(isprime(i)){
                count++;
            }
        }
        int a=count;
        int b=n-a;
        return (fact(a)*fact(b))%mod;
    }
};