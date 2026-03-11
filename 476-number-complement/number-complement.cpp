class Solution {
public:
    int findComplement(int n) {
           if(n==0){
            return 1;
        }
        string s="";
        while(n>0){
            int rem=n%2;
            s.push_back((rem+'0'));
            n=n/2;
        }
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
              s[i]='1'-s[i]+'0';
        }
        // cout<<s<<endl;
        int num=0;
        int size=s.length();
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                num=num+pow(2,size-i-1);
            }
        }
        return num;
    }
};