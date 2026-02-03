class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool flag=true;
        int i=1;
        int n=nums.size();
        if(n<4){
            return false;
        }
        int p;
        int q;

        while(i<n){
            if(nums[i-1]<nums[i]){  
                i++;
            }
           else{
            break;
           }
        }

        if(i==1 || i==n-1){
            return false;
        }
        p=i-1;
        
        while(i<n){
            if(nums[i]<nums[i-1]){
                i++;
            }
            else{
                break;
            }
        }
        q=i-1;
        if(i==n){
            return false;
        }
        while(i<n){
            if(nums[i-1]<nums[i]){
                i++;
            }
            else{
                break;
            }
        }
        if(i==n){
            return true;
        }
        return false;
    }
};