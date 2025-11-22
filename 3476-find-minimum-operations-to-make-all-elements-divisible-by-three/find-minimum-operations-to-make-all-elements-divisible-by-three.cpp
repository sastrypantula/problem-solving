class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int count=0;
        //  for(int it:nums){
               
        //     if(it%3==0){
                
        //         continue;
        //     }
        //     else if(((it-1)%3==0) || ((it+1)%3==0)){
                
        //         count+=1;
        //     }
        //     else if(((it-2)%3==0) || ((it+2)%3==0)){
               
        //         count+=2;
        //     }
        //  }
        for(int it:nums){
            if(it%3==0){
                continue;
            }
            else{
                count++;
            }
        }
         return count;
    }
};