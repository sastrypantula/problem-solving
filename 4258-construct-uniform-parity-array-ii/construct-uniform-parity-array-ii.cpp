class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool eve=true;
        bool odd=true;
        //    set<int> oddnums,evenums;
        int minieve=INT_MAX;
        int miniodd=INT_MAX;
       for(int it:nums1){
        if(it%2==1){
            eve=false;
            // evenums.insert(it);
            miniodd=min(miniodd,it);
        }
        if(it%2==0){
            odd=false;
            // oddnums.insert(it);
           minieve=min(minieve,it);

        }
       } 
       if(eve || odd){
        return true;
       }

       // eve
       bool flag1,flag2=true;
       for(int i=0;i<nums1.size();i++){
        if(nums1[i]%2==0){
            continue;
        }
        else{
             if(nums1[i]-miniodd>=1 && nums1[i]!=miniodd){
                continue;
             }
             else{
                flag1=false;
                break;
             }
        }

       }

       // odd
       for(int i=0;i<nums1.size();i++){
        if(nums1[i]%2==1){
            continue;
        }
        else{
             if(nums1[i]-miniodd>=1 && nums1[i]!=miniodd){
                continue;
             }
             else{
                flag2=false;
                break;
             }
        }

       }
       if(flag1 || flag2) return true;
       return false;
    }
};