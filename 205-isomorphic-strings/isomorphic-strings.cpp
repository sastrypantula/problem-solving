class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mymap;
        unordered_map<char,char> freq;
        for(int i=0;i<s.length();i++){
            if(mymap.find(s[i])==mymap.end() && freq.find(t[i])==freq.end()){
                mymap[s[i]]=t[i];
                freq[t[i]]=s[i];
            }
            else if(mymap[s[i]]==t[i] && freq[t[i]]==s[i]){
                continue;
            }
            else{
                return false;
            }

        }
        return true;
    }
};