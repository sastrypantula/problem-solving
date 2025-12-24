class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples_count=0;
        for(int i=0;i<apple.size();i++){
            apples_count+=apple[i];
        }
        sort(capacity.begin(),capacity.end());
        int count=0;
       for(int i=capacity.size()-1;i>=0;i--){
           if(apples_count<=0){
            break;
           }
           apples_count=apples_count-capacity[i];
           count++;
       }
       return count;
    }
};