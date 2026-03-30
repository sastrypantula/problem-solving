// class Solution {
// public:
//     bool checkStrings(string s1, string s2) {
//         if(s1==s2){
//             return true;
//         }
//         int n=s1.length();
//         unordered_map<char,set<int>> even;
//         unordered_map<char,set<int>> odd;
//         for(int i=0;i<n;i++){
//             if(i%2==0){
//             even[s1[i]].insert(i);
//             }
//             else{
//                 odd[s1[i]].insert(i);
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(s1[i]==s2[i]){
//                 mymap[s1[i]].erase(i);
               
//                 continue;
//             }
//             else{
//                 char ch=s2[i];
//                 if(mymap.find(ch)==mymap.end()){
//                      cout<<"broke here in"<<"index is "<<i<<" "<<s1[i]<<endl;
//                     return false;
//                 }
//                 set<int> myset=mymap[s2[i]];
//                 bool flag=false;
//                 for(auto it=myset.begin();it!=myset.end();it++){
//                     int j=*it;
//                     if((j-i)%2==0){
//                       flag=true;
//                       mymap[ch].erase(j);
//                       mymap[s1[i]].erase(i);
//                       if(mymap[ch].empty()){
//                         mymap.erase(ch);
//                       }
//                       mymap[s1[i]].insert(j);
//                       swap(s1[i],s1[j]);
//                     }
//                 }
//                 if(flag==false){
//                      cout<<"broke here out"<<endl;
//                      return false;
//                 }

//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1 == s2){
            return true;
        }

        int n = s1.length();

        unordered_map<char, set<int>> even, odd;

        // build maps
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                even[s1[i]].insert(i);
            } else {
                odd[s1[i]].insert(i);
            }
        }

        for(int i = 0; i < n; i++){
            if(s1[i] == s2[i]){
                // remove from correct map
                if(i % 2 == 0){
                    even[s1[i]].erase(i);
                } else {
                    odd[s1[i]].erase(i);
                }
                continue;
            }

            char ch = s2[i];

            if(i % 2 == 0){
                // need from even positions
                if(even[ch].empty()){
                    return false;
                }

                int j = *even[ch].begin();   // take any valid index

                // update maps
                even[ch].erase(j);
                even[s1[i]].erase(i);
                even[s1[i]].insert(j);

                swap(s1[i], s1[j]);
            }
            else{
                // need from odd positions
                if(odd[ch].empty()){
                    return false;
                }

                int j = *odd[ch].begin();

                // update maps
                odd[ch].erase(j);
                odd[s1[i]].erase(i);
                odd[s1[i]].insert(j);

                swap(s1[i], s1[j]);
            }
        }

        return true;
    }
};