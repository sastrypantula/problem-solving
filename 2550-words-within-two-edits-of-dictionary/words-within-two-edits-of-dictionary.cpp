class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
      vector<string> ans;
      unordered_set<string> myset(dictionary.begin(),dictionary.end());
      for(auto s:queries){
        if(myset.count(s)){
            ans.push_back(s);
            continue;
        }
        for(auto t:dictionary){
            int i=0;
            int j=0;
            int n=t.length();
            int count=0;
            bool flag=true;
            while(i<n && j<n){
                if(s[i]!=t[j]){
                    count++;
                    if(count>2){
                        flag=false;
                        break;
                    }
                }
                i++;
                j++;
            }
            if(flag){
                ans.push_back(s);
                break;
            }
        }
      }
       
      return ans;
    }
};