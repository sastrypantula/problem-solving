class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        string temp="abcdefghijklmnopqrstuvwxyz";
        reverse(temp.begin(),temp.end());
        for(auto& s:words){
            int sum=0;
            for(char& ch:s){
                int i=ch-'a';
                sum=sum+weights[i];
            }
            sum=sum%26;
            ans.push_back(temp[sum]);

            
        }
        return ans;
    }
};