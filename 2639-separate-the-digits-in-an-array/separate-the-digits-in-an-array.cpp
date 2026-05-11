class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            int j=0;
            while(j<temp.size()){
                int dig=temp[j]-'0';
                ans.push_back(dig);
                j++;
            }
        }
        return ans;
    }
};