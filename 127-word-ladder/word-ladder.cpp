class Solution {
public:
bool compare(string& s1,string& s2){
    int n=s1.length();
    int i=0;
    int j=0;
    int count=0;
    while(i<n){
        if(s1[i]!=s2[j]){
            count++;
        }
        if(count>1){
            return false;
        }
        i++;
        j++;
    }
    return true;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mymap;
        for(auto& s:wordList){
            if(compare(s,beginWord)){
                mymap[beginWord].push_back(s);
                mymap[s].push_back(beginWord);
            }
        }
        for(auto& s1:wordList){
            for(auto& s2:wordList){
                if(s1!=s2 && compare(s1,s2)){
                     mymap[s1].push_back(s2);
                    
                }
            }
        }
        
     unordered_map<string,int> freq;
     queue<string> q;
     int count=1;
     q.push(beginWord);
     freq[beginWord]++;
     while(!q.empty()){
        int n=q.size();
        count++;
         while(n--){
            string s=q.front();
            q.pop();
            for(auto s1:mymap[s]){
                if(s1==endWord){
                    return count;
                }
                if(freq[s1]==0){
                    q.push(s1);
                    freq[s1]++;
                }
            }
         }
     }
return 0;
    }
};