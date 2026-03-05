class Solution {
public:
    int minOperations(string s) {
        int count1=0;
        int count2=0;
        int n=s.length();
        if(n==1){
            return 0;
        }
        string temp1="0";
        string temp2="1";
        for(int i=1;i<n;i++){
            char ch1=('1'-temp1[i-1])+'0';
            char ch2=('1'-temp2[i-1])+'0';
            temp1.push_back(ch1);
            temp2.push_back(ch2);
        }
  
        for(int i=0;i<n;i++){
            if(temp1[i]!=s[i]){
               
                count1++;
            }
            if(temp2[i]!=s[i]){
                count2++;
            }
        }
     
        return min(count1,count2);
    }
};