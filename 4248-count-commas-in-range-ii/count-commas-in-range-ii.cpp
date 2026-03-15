class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long start=1000;
        int commas=1;
        while(start<=n){
              long long end = start * 1000 - 1;   
            
            if(n <= end){
                ans += (n - start + 1) * commas;
                break;
            }
            else{
                ans += (end - start + 1) * commas;
            }

            start = start*1000;
            commas++;
        }
        return ans;
    }
};