class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.length();
        string temp="";
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
               reverse(temp.begin(),temp.end());
               ans+=temp;
               ans+=' ';
               temp="";
            }
            else{
                temp.push_back(s[i]);
            }
        }
        if(!temp.empty()){
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }
        cout<<ans<<endl;
        string res="";
        int i;
        while(ans[i]==' ' && i<ans.length()){
            i++;
        }
        while(i<ans.length()-1){
            if(ans[i]==' ' && ans[i+1]==' '){
                i++;
                continue;
            }
            else{
                res.push_back(ans[i]);
            }
            i++;

        }
        if(ans[ans.length()-1]!=' '){
            res.push_back(ans[ans.length()-1]);
        }

        return res;

    }
};