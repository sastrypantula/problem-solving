// class Solution {
// public:
//     int minDeletions(string s) {
//         map<char,int> mymap;
//         for(char ch:s){
//             mymap[ch]++;
//         }
//         unordered_map<int,unordered_set<char>>freq;
//         for(auto [ch,counts]:mymap){
//             freq[counts].insert(ch);
//         }

//         int ans=0;
//         for(auto [ch,counts]:mymap){
//                if(freq.count(counts)){
//                 unordered_set<char>& myset=freq[counts];
//                 for(auto& it:myset){
//                     if(it!=ch){
//                         while(freq.count(mymap[it])){
//                             mymap[it]--;
//                             ans++;
//                         }
//                         if(mymap[it]==0){
//                             mymap.erase(it);
//                             myset.erase(it);
//                         }
//                         else{
//                             myset.erase(it);
//                             freq[mymap[it]].insert(it);
//                         }
//                     }
//                 }
//                }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mymap;
        for(char ch:s){
            mymap[ch]++;
        }

        unordered_map<int,unordered_set<char>> freq;
        for(auto [ch,counts]:mymap){
            freq[counts].insert(ch);
        }

        int ans=0;
        for(auto [ch,counts]:mymap){
            if(freq.count(counts)){
                unordered_set<char>& myset = freq[counts];

                // ✅ use iterator loop instead of range-based
                for(auto it = myset.begin(); it != myset.end(); ) {
                    if(*it != ch) {
                        while(freq.count(mymap[*it])) {
                            mymap[*it]--;
                            ans++;
                        }

                        if(mymap[*it] == 0) {
                            mymap.erase(*it);
                            it = myset.erase(it); // erase returns next valid iterator
                        } else {
                            char val = *it;
                            it = myset.erase(it); // erase safely
                            freq[mymap[val]].insert(val);
                        }
                    } else {
                        ++it; // only increment if not erased
                    }
                }
            }
        }
        return ans;
    }
};