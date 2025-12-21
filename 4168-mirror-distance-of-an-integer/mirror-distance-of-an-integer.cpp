class Solution {
public:
    int mirrorDistance(int n) {
    //     int t=0;
    //     int temp=n;
    //     int i=0;
    //     bool last=true;
    //     while(temp>0){
    //        int rem=temp%10;
    //        if(rem!=0 || last==false){
    //         last=false;
    //         t=t*10+rem;
    //         i++;
    //        }
    //        temp=temp/10;
    //     }
    //   return abs(t-n);
      int original = n;
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return abs(original - rev);
    }
};