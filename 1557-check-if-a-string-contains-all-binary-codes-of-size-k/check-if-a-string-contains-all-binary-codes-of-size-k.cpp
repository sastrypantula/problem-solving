class Solution {
public:
 unordered_set<string> myset;
 bool func(string& temp,int k){
if(temp.length()==k){
    if(myset.count(temp)){
        return true;
    }
    return false;
}
temp.push_back('0');
bool left=func(temp,k);
  temp.pop_back();
temp.push_back('1');
bool right=func(temp,k);
  temp.pop_back();
if(left && right){
    return true;
}
else{
    return false;
}
 }
    bool hasAllCodes(string s, int k) {
       
        int i=0;
        int j=0;
        int n=s.length();
        string temp="";
        while(j<n){
             temp.push_back(s[j]);
            if(j-i+1==k){
                myset.insert(temp);
                temp.erase(0,1);
                i++;
            }
            j++;
        }
        string t="";
      return func(t,k);
    }
};