class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total=0;
        for(int it:arr){
            total+=it;
        }
        if(total%3!=0){
         return false;
        }
        int target=total/3;
        int sum=0;
        int parts=0;
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];
            if(sum==target){
                parts++;
                sum=0;
            }
            if(parts==2 && i<arr.size()-1){
                return true;
            }
        }
        return false;
    }
};