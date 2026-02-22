class Solution {
public:
    string maximumXor(string s, string t) {
        int n=s.length();
        string temp="";
        int count_ones=0;
        int count_zeros=0;
        for(char k:t){
            if(k=='0'){
                count_zeros++;
            }
            else{
                count_ones++;
            }
        }
        for(char k:s){
            if(k=='1'){
                if(count_zeros>0){
                    temp.push_back('1');
                    count_zeros--;
                }
                else{
                    temp.push_back('0');
                }
            }
            if(k=='0'){
                if(count_ones>0){
                    temp.push_back('1');
                    count_ones--;
                }
                else{
                    temp.push_back('0');
                }
            }
        }
        return temp;

    }
};