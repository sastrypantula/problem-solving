class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n =nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        bool zero=true;
        for(int i=1;i<n;i++){
            if(nums[i]>0){
                zero=false;
            }
            prefix[i]=nums[i]+prefix[i-1];
        }
        // if(zero && nums[0]==0){
        //     return 0;
        // }
        int valid=0;
        for(int i=0;i<n;i++){
            if(i==0){
              if(nums[0]==0 && prefix[n-1]==1){
                valid++;
              }
              else if(nums[0]==0 && prefix[n-1]==0){
                valid+=2;
              }
            }
           else if(nums[i]==0){
                if(prefix[n-1]-prefix[i]==prefix[i-1]){
                    valid=valid+2;
                }
                else if(abs((prefix[n-1]-prefix[i]-prefix[i-1]))==1){
                    valid++;
                }
            }
        }
        return valid;
    }
};