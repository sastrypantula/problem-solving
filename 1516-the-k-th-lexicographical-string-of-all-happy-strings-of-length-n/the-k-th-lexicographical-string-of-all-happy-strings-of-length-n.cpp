class Solution {
public:
string ans="";
int count=0;
void func(string& s,int n,int k){
    if(ans!=""){
        return;
    }
    if(s.length()==n){
        count++;
       if(count==k){
        ans=s;
        return;
       }
       return;
    }
    for(char ch='a';ch<='c';ch++){
      if(s.empty() || s.back()!=ch){
        s.push_back(ch);
        func(s,n,k);
        s.pop_back();
      }
    }
}
    string getHappyString(int n, int k) {
        string s="";
        func(s,n,k);
        return ans;
    }
};