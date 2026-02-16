class Solution {
public:
    int reverseBits(int n) {
        string s="";
        while(n>0){
            int rem=n%2;
            s.push_back(rem+'0');
            n=n/2;
        }
        while(s.length()<32){
            s.push_back('0');
        }
        int j=0;
        int num=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                num=num+pow(2,j);

            }
            j++;
        }
        return num;
    }
};