class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> myset(arr.begin(),arr.end());
        int count=0;
        int i=1;
        while(true){
            if(myset.find(i)==myset.end()){
                count++;
            }
            if(count==k){
                return i;
            }
            i++;
        }
        return -1;
    }
};