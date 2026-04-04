class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        
        string base = (n1 < n2) ? str1 : str2;
        string ans = "";

        for(int i = 0; i < base.length(); i++){
            string temp = base.substr(0, i+1);

            string res1 = "";
            while(res1.length() < n1){
                res1 += temp;
            }

            string res2 = "";
            while(res2.length() < n2){
                res2 += temp;
            }

            if(res1 == str1 && res2 == str2){
                ans = temp;
            }
        }

        return ans;
    }
};