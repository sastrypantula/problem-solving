class Solution {
public:
    int minLengthAfterRemovals(string s) {
       stack<char>st;
       int n=s.length();
       int count1=0;
       st.push(s[0]);
       for(int i=1;i<n;i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(!st.empty() && st.top()==s[i]){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
        }
       } 
       return st.size();
    }
};