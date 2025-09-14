class Solution {
public:
    int maxFreqSum(string s) {
       int result=0;
       int n=s.length();
       vector<int>freq(26,0);
       for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
       } 
       int vowel=0;
       int cont=0;
       for(int i=0;i<n;i++){
         if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
            vowel=max(vowel,freq[s[i]-'a']);
         }
         else{
            cont=max(cont,freq[s[i]-'a']);
         }
       }
       return vowel+cont;
    }
};