class Solution {
public:
    bool checkPerfectNumber(int num) {
        // int sum=0;
        // for(int i=1;i<=num-1;i++){
        //     if(num%i==0){
        //         sum+=i;
        //     }
        // }
        // if(num>0 && sum==num){
        //     return true;
        // }
        // return false;
        if(num==1) return false;
        int sum =1;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                sum+=(i+(num/i));
            }
        }
        if(sum==num){
            return true;
        }
        else return false;
    }
};