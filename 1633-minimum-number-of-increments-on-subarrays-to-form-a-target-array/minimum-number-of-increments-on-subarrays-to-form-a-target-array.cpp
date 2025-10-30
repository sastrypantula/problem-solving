class Solution {
public:
// GOOD problem next time think again for more time to get this approach /////
    int minNumberOperations(vector<int>& target) {
        int res=0;
        int prev=0;
        int curr=0;
        for(int i=0;i<target.size();i++){
            curr=target[i];
            if(curr>0 && prev<0 || curr<0 && prev>0){
                res+=abs(curr);
            }
            else if(curr>prev){
                res+=abs(curr)-abs(prev);
            }
          
            prev=curr;
        }
        return res;
    }
};