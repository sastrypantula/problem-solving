class Solution {
public:
    int minFlips(string s) {
        int ans=INT_MAX;
        int k=s.length();
        int n=2*k;
        string temp1="1";
        string temp2="0";
        for(int i=1;i<n;i++){
            temp1.push_back('1'-temp1[i-1]+'0');
            temp2.push_back('1'-temp2[i-1]+'0');
        }
       int i=0;
       while(i<k){
        s.push_back(s[i]);
        i++;
       }
       int flip1=0;
       int flip2=0;
        i=0;
       int j=0;
       while(j<n){
        if(s[j]!=temp1[j]){
            flip1++;
        }
          if(s[j]!=temp2[j]){
            flip2++;
        }
        if(j-i+1>k){
            if(s[i]!=temp1[i]){
                flip1--;
            }
            if(s[i]!=temp2[i]){
                flip2--;
            }
           i++;
        }
        if(j-i+1==k){
            ans=min({flip1,flip2,ans});

        }
        j++;
       }
       return ans;
    }
};