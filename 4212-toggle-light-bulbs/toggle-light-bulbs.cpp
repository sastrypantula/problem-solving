class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
       vector<int> ans;
       vector<int> temp(101,0);
       for(int i=0;i<bulbs.size();i++){
        temp[bulbs[i]]=1-temp[bulbs[i]];
       }
       for(int i=1;i<=100;i++){
        if(temp[i]==1){
            ans.push_back(i);
        }
       }
       return ans;

    }
};