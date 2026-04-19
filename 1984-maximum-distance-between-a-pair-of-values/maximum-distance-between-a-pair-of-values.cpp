class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
       int ans=0;
       for(int i=0;i<nums1.size();i++){
        int target=nums1[i];
        int ind=-1;
         int low=0;
         int high=nums2.size()-1;
         while(low<=high){
            int mid=(low+high)/2;
            if(target<=nums2[mid]){
                ind=max(ind,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
         }
         if(ind!=-1){
            ans=max(ans,ind-i);
         }
       } 
       return ans;
    }
};