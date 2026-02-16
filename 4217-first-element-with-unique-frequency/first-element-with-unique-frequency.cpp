class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int n=nums.size();
        vector<vector<int>> temp(n+1);
        for(int i=0;i<n;i++){
            mymap[nums[i]]++;
        }
        for(auto& it:mymap){
            int key=it.first;
            int value=it.second;
            temp[value].push_back(key);
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            int ele=nums[i];
            int val=mymap[ele];
            if(temp[val].size()==1){
                return ele;
            }
        }
        return ans;

    }
};