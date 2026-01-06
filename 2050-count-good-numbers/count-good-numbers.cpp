// class Solution {
// public:
// const int MOD=1e9+7;
//     int countGoodNumbers(long long n) {
//         int ans=0;
//          long long t=n/2;
//         if(n%=2==0){
           
//             ans=((pow(5*t)%MOD)*(pow(4,t)%MOD))%MOD;
//             return ans;
//         }
//            ans=((pow(5*(t+1))%MOD)*(pow(4,t)%MOD))%MOD;
//            return ans;
//     }
// };

class Solution {
public:
    const int MOD = 1e9+7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; 
        long long oddCount  = n / 2;       

        long long ans = (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
        return (int)ans;
    }
};