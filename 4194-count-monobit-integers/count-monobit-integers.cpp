class Solution {
public:
    int countMonobit(int n) {
        int ans=1;
        int i=0;
        int sum=0;
       while(true){
        sum=sum+pow(2,i);
        if(sum<=n){
            ans++;
            i++;
        }
        else{
            break;
        }
       }
        return ans;
    }
};