class Solution {
public:
    bool checkOnesSegment(string s) {
        int count=0;
        int ans=0;
        int n=s.length();
        if(n==1 && s[0]=='0'){
            return false;
        }
        if(n==1 && s[0]=='1'){
            return true;
        }
        for(int i=0;i<n;i++){
              if(s[i]=='1'){
                count++;
              }
              else{
               if(count>=1){
                ans++;
               }
               count=0;
              }
        }
        if(count>=1){
            ans++;
        }
        if(ans<=1){
            return true;
        }
        return false;

    }
};