class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        // first we will do for 1 's to see 0 1 pair
        int count1=0;
        int j=0;
        int i=0;
        while(j<n){
            if(s[j]=='1'){
                i=j-1;
                while(i>=0 && s[i]=='0' && s[j]=='1'){
                     count1++;
                     i--;
                     j++;
                }
            }
            j++;
        }
        int count2=0; // to count 10  pairs
        j=0;
        i=0;
         while(j<n){
            if(s[j]=='0'){
                i=j-1;
                while(i>=0 && s[i]=='1' && s[j]=='0'){
                     count2++;
                     i--;
                     j++;
                }
            }
            j++;
        }
        return count1+count2;
    }
};