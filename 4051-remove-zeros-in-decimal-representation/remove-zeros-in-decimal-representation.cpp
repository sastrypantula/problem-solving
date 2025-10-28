class Solution {
public:
    long long removeZeros(long long n) {
        // string ans=to_string(n);
        // string res="";
        // for(int i=0;i<ans.length();i++){
        //     if(ans[i]!='0'){
        //         res=res+ans[i];
        //     }
        // }
        // return stoll(res);
         long long result = 0, place = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                result += digit * place;
                place *= 10;
            }
            n /= 10;
        }

        return result;
    }
};