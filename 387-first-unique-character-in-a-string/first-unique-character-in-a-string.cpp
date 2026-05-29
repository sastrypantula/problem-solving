class Solution {
public:
    int firstUniqChar(string s) {
        int index=INT_MAX;
        unordered_map<char,int> mymap1,mymap2;
        for(char ch:s){
            mymap1[ch]++;
        }
        for(int i=0;i<s.length();i++){
            mymap1[s[i]]--;
            mymap2[s[i]]++;
            if(mymap1[s[i]]==0 && mymap2[s[i]]==1){
                index=i;
                break;
            }
        }
        if(index==INT_MAX) return -1;
        return index;

    }
};