class Solution {
public:
int sum=0;
    void chk(int n){
        int count=0;
        int s=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count++;
                s+=i;
            }
            if(count>4){
                s=0;
                break;
            }
          
        }
        if(count==4)
        sum=sum+s;
        
    }
    int sumFourDivisors(vector<int>& nums) {
      for(int it:nums){
        chk(it);
      }
        return sum;
    }
};