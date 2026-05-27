class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mymap1;
        vector<bool> temp(26,false);
        int ans=0;
        for(char ch:word){
            if('a'<=ch && ch<='z'){
                mymap1[ch]++;
            }
        }
        unordered_map<char,int> mymap2;
        for(char ch:word){
          if('a'<=ch && ch<='z'){
            mymap2[ch]++;
            mymap1[ch]--;
          }
          if('A'<=ch && ch<='Z'){
            char alphabet=ch+32;
            if(mymap1[alphabet]<=0 && mymap2[alphabet]>0 && temp[alphabet-'a']==false){
               
               ans++;
            }
             temp[alphabet-'a']=true;
          }
        }
        return ans;
    }
};