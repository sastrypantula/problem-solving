class Solution {
public:
    // long long func(string &s){

    //     long long i=0;
    //     long long n=s.length();
    //     long long j=n-1;
    //     long long num=1;
    //     while(j>=0){
    //         if(s[j]=='1'){
    //             num=num+pow(2,i);
             
    //         }
    //         i++;
    //         j--;
    //     }
    //     return num;


    // }
    string addBinary(string a, string b) {
      int i=a.length()-1;
      int j=b.length()-1;
      int carry=0;
      string ans="";
      while(i>=0 || j>=0 || carry){
        int sum=carry;
        if(i>=0){
           sum=sum+a[i]-'0';
           i--;
        }
        if(j>=0){
            sum=sum+b[j]-'0';
            j--;
        }
        carry=sum/2;
        ans=ans+to_string(sum%2);
      }
      reverse(ans.begin(),ans.end());
      return ans;
   
    }
};