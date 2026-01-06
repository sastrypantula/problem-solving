class Solution {
public:
double powe(double x,long long n){
if(n==0 || x==1){
    return 1.0;
}
if(n%2==0){
    return powe(x*x,n/2);
}
return x*powe(x*x,(n-1)/2);


}
    double myPow(double x, int n) {
        int num=n;
        if(num<0){
            return 1.0/powe(x,-1.0*n);
        }
        return powe(x,n);
    }
};