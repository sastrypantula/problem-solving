class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long long num=0;
        int sign=1;
           int i=0;
              while(i<n){
            if(s[i]==' '){
                i++;
                continue;
            }
            else{
               break;
            }          
        }
        if(s[i]=='+'){
            sign=1;
            i++;
        }
        else if(s[i]=='-'){
            sign=-1;
            i++;
        }
     
     
        if(i==n){
            return 0;
        }
        if('a'<=s[0] && s[0]<='z'){
            return 0;
        }
        string t="";
        while(i<n){
            if('a'<=s[i] && s[i]<='z' || s[i]=='-' || s[i]=='+' || s[i]==' ' || s[i]=='.'){
              break;
            }
            else{
                t.push_back(s[i]);
            }
            i++;
        }
        cout<<t<<endl;
        i=0;
        while(i<t.length()){
            if(t[i]=='0'){
                i++;
                continue;
            }
            else{
               break;
            }
        }
  
        while(i<t.length()){
             cout<<"e"<<endl;
                cout<<t[i]<<endl;
            int q=t[i]-'0';
            num=num*10+(q);
            if(num>INT_MAX){
                cout<<"returned here"<<endl;
               if(sign==-1){
                return INT_MIN;
               }
               return INT_MAX;
            }
            i++;
        }
        if(sign*num<=INT_MIN){
            return INT_MIN;
        }
          if(sign*num>=INT_MAX){
            return INT_MAX;
        }
        return (long long)sign*num;
    }
};