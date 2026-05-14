class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(201,0);
        int maxi=INT_MIN;
        for(int it:nums){
            temp[it]++;
            maxi=max(maxi,it);
        }
        for(int i=1;i<=maxi;i++){
       
           if(i==maxi && temp[i]!=2){
            return false;
           }
           if(i!=maxi && temp[i]!=1){
            return false;
           }

        }
        return true;

    }
};