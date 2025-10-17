class Solution {
public:
    string toHex(int num) {
        unsigned int a=num;
        string res="";
        string s="0123456789abcdef";
        if(num==0)return "0";
        while(a>0){
            int temp=a%16;
            res=s[temp]+res;
            a=a/16;
        }
        return res;
    }
};