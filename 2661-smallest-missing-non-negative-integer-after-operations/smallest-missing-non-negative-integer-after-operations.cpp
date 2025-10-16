class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int>mymap;
        for(int it:nums){
        int temp=((it%value)+value)%value;
        mymap[temp]++;
        }
        int mex=0;
        while(mymap[mex%value]>0){
            mymap[mex%value]--;
            mex++;
        }
        return mex;
    }
};