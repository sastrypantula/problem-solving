class Solution {
public:
    string frequencySort(string s) {
  
       unordered_map<char,int> mymap;
        int n=s.length();
        for(auto it:s){
            mymap[it]++;
        }
        vector<pair<char,int>> temp(mymap.begin(),mymap.end());
        sort(temp.begin(),temp.end(),[](auto& a,auto& b){
            return a.second>b.second;
        });
        int j=0;
        for(int i=0;i<temp.size();i++){
          char ch=temp[i].first;
          int count=temp[i].second;
          while(count>0){
            s[j]=ch;
            j++;
            count--;
          }
        }
        return s;
    }
};