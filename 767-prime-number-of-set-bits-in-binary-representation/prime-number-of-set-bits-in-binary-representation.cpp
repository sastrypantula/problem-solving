class Solution {
public:
int chk(int num){
    if(num==1){
        return false;
    }
    for(int i=2;i*i<=num;i++){
        if(i!=num && num%i==0){
            return false;
        }
    }
    return true;
}
int func(int x){
int count=0;
for(int i=0;i<32;i++){
    if((x & (1<<i))!=0){
        count++;
    }
}
return count;

}
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int t=func(i);
            if(chk(t)){
                ans++;
                cout<<ans<<"for the i"<<i<<endl;
            }
        }
        return ans;
    }
};