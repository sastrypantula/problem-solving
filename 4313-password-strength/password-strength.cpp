class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
        unordered_set<char> myset;
        for(char ch:password){
            if(myset.find(ch)==myset.end()){
                if('a'<=ch && ch<='z'){
                    ans++;
                    myset.insert(ch);
                }
                 if('A'<=ch && ch<='Z'){
                    ans=ans+2;
                    myset.insert(ch);
                }
                 if('0'<=ch && ch<='9'){
                    ans=ans+3;
                    myset.insert(ch);
                }
                 if(ch=='!' || ch=='@' || ch=='#' || ch=='$'){
                    ans=ans+5;
                    myset.insert(ch);
                }
            }
        }
        return ans;
    }
};