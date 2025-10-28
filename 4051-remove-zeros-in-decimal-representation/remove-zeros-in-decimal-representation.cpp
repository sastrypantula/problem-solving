class Solution {
public:
    long long removeZeros(long long n) {
        string ans=to_string(n);
        string res="";
        for(int i=0;i<ans.length();i++){
            if(ans[i]!='0'){
                res=res+ans[i];
            }
        }
        return stoll(res);
    }
};