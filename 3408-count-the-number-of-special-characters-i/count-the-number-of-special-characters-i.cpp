class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> temp1(26,0);
        vector<int> temp2(26,0);
        int n=word.length();
        for(int i=0;i<n;i++){
            char ch=word[i];
            if('a'<=ch && ch<='z'){
                temp1[ch-'a']++;
            }
            else{
                temp2[ch-'A']++;
            }
        }
     int ans=0;
     for(int i=0;i<26;i++){
        if(temp1[i]>0 && temp2[i]>0){
            ans++;
        }
     }
     return ans;
    }
};