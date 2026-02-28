class Solution {
public:
    int numSteps(string s) {
      long long num=0;
        // long long j=1;
        // for(int i=s.length()-1;i>=0;i--){
        //     if(s[i]=='1'){
        //         num=num+j;
        //     }
        //     j=j*2;

        // }
        int ans=0;
        while(s!="1"){
            if(s.back()=='0'){
                s.pop_back();
            }
            else{
                int i=s.length()-1;
                while(i>=0 && s[i]=='1'){
                    s[i]='0';
                    i--;
                }
                if(i>=0){
                  s[i]='1';
                }
                else{
                    s.insert(s.begin(),'1');
                }
            }
            ans++;
        }
        return ans;
    }
};