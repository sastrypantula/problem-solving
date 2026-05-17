class Solution {
public:
long long func(long long i,int k){
    if(k==0){
        return 1;
    }
    long long half=func(i,k/2);
    if(k%2==0){
        return half*half;
    }
        return half*half*i;
    
}
    int countKthRoots(int l, int r, int k) {
        int ans=0;
        if(k==1){
            return r-l+1;
        }
       
        for(int i=0;;i++){
            long long temp=func(i,k);
            if(temp>r) break;
            if(l<=temp && temp<=r){
                ans++;
            }
        }
        return ans;
    }
};