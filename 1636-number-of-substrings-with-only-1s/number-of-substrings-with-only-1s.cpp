class Solution {
public:
    int numSub(string s) {
        int n=s.length();
            const int MOD=1e9+7;
        int count=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                temp++;
            }
            else{
        
            int res=((long long)temp*(temp+1)/2)%MOD;
            count+=res;
            temp=0;
           
            }
        }
        if(temp>0){
            int res=((long long)temp*(temp+1)/2)%MOD;
            count+=res;
        }
        return count;
    }
};