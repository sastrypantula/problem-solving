class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=0;
        for(int i=1;i<=num-1;i++){
            if(num%i==0){
                sum+=i;
            }
        }
        if(num>0 && sum==num){
            return true;
        }
        return false;
    }
};