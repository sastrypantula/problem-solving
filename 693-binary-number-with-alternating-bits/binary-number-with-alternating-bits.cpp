class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
    
        while(n>0){
            int rem=n%2;
            s.push_back((rem)+'0');
            n=n/2;
        }
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                return false;
            }
        }
        return true;
    }
};