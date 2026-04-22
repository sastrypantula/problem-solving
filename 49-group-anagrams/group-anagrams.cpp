class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mymap;
        vector<vector<string>> ans;
        for(auto s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
    
            mymap[temp].push_back(s);
        }
        for(auto it:mymap){
              string key=it.first;
              ans.push_back(mymap[key]);
        }
        return ans;
    }
};