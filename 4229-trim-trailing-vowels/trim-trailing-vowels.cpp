class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.length();
        int i=n-1;
        while(i>=0){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                i--;
                continue;
            }
            else{
                break;
            }
            i--;
        }
        return s.substr(0,i+1);
    }
};