class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>myset;
        for(char ch:s){
            myset.insert(ch);
        }
        int count=0;
        for(char ch:myset){
            int left_idx=-1;
            int right_idx=-1;
            for(int i=0;i<s.length();i++){

                if(s[i]==ch){
                if(left_idx==-1){
                    left_idx=i;
                }
                right_idx=i;
                }
            }
            unordered_set<char>st;
            for(int i=left_idx+1;i<right_idx;i++){
                st.insert(s[i]);
            }
            count+=st.size();
        }
        return count;
    }
};