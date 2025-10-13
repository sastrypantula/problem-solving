class Solution {
public:
bool chk(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string> res;
        res.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(!chk(words[i],words[i-1])){
            res.push_back(words[i]);
            }
        }
        return res;
    }
};