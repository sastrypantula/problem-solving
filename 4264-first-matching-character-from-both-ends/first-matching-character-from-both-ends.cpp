class Solution {
public:
    int firstMatchingIndex(string s) {
      int ans=-1;
      int n=s.length();
      for(int i=0;i<s.length();i++){
        if(s[i]==s[n-i-1]){
            ans=i;
            break;
        }
      }  
      return ans;
    }
};