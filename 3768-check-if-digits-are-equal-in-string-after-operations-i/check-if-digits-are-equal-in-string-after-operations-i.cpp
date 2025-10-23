class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.length();
     
        while(s.length()>2){
               string res="";
            for(int i=0;i<s.length()-1;i++){
                int a=s[i]-'0';
                int b=s[i+1]-'0';
                res+=((a+b)%10)+'0';
            }
            s=res;
        }
        return s[0]==s[1];
    }
};