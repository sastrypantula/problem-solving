class Solution {
public:
int chk(int n){
    if(n==0){
        return 1;
    }
    int temp=1;
    for(int i=1;i<=n;i++){
    temp=temp*i;
    }
    return temp;
}
    bool isDigitorialPermutation(int n) {
        int ans=0;
        int t=n;
        string temp1=to_string(n);
        while(n>0){
            int rem=n%10;
            
            ans=ans+chk(rem);
 
            n=n/10;
        }
        cout<<ans<<endl;
        sort(temp1.begin(),temp1.end());
        cout<<temp1<<endl;
        string temp2=to_string(ans);
        sort(temp2.begin(),temp2.end());
        cout<<temp2<<endl;

        return temp1==temp2;
    }
};