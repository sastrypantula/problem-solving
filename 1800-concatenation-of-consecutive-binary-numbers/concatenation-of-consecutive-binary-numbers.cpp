class Solution {
public:
const int mod=1e9+7;
// string numtobin(int num){
    // string s="";
//     while(num>0){
//         int rem=num%2;
//         s.push_back(rem+'0');
//         num=num/2;
//     }
//     reverse(s.begin(),s.end());
//     return s;
// }
    int concatenatedBinary(int n) {
//           string s = "";
//         for (int i = 1; i <= n; i++) {
//             s += numtobin(i); 
//         }

//         long long num = 0;
//         int j = 0;

       
//         for (int i = s.length() - 1; i >= 0; i--) {
//             if (s[i] == '1') {
//                 num = (num + (1LL << j)) % mod;
//             }
//             j++;
//         }

//         return (int)(num % mod);

long result=0;
for(int i=1;i<=n;i++){
    int digits=log2(i)+1;
    result=(((result<<digits)%mod)+i)%mod;
}
return result;

    }
};