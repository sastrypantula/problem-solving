class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(!st.empty()){
                ans.push_back('(');
                }
                st.push('(');
            }
            else{
                if(!st.empty()){
                    st.pop();
                    if(!st.empty()){
                        ans.push_back(')');
                    }
                }
            }
        }
        return ans;
    }
};