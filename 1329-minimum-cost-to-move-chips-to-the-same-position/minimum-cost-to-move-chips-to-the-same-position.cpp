class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenplace=0;
        for(int it:position){
            if(it%2==1){
                evenplace+=1;
            }
        }
        int oddplace=0;
        for(int it:position){
              if(it%2==0){
                oddplace+=1;
              }
        }
        return min(evenplace,oddplace);
    }
};