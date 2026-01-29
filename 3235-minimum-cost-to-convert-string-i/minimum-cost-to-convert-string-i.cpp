// class Solution {
// public:
//     long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
//         long long ans=0;
//         int n=source.length();
//         unordered_map<char,vector<int>> mymap;
//           for (char c = 'a'; c <= 'z'; ++c) {
//         mymap[c] = vector<int>(26, INT_MAX);
//     }
//         unordered_set<char> myset;
//        for(char ch:original){
//         myset.insert(ch);
//        }
//        for(char ch:changed){
//         myset.insert(ch);
//        }

//        for(int i=0;i<original.size();i++){
//         char s=original[i];
//         int  t=changed[i]-'a';
//         mymap[s][t]=cost[i];
//        }
//        for(char ch='a';ch<='z';ch++){
//         mymap[ch][ch-'a']=0;
//        }
//        for(char ch='a';ch<='z';ch++){
//         if(myset.find(ch)!=myset.end()){
//             for(char i='a';i<='z';i++){
//                 for(char j='a';j<='z';j++){
//                     if(i==j){
//                         continue;
//                     }
//                     if (mymap[i][ch - 'a'] != INT_MAX && mymap[ch][j - 'a'] != INT_MAX) {
//     mymap[i][j - 'a'] = min(mymap[i][j - 'a'],
//                             mymap[i][ch - 'a'] + mymap[ch][j - 'a']);
// }
//                 }
//             }
//         }
//        }
     

//        for(int i=0;i<n;i++){
//         if(source[i]!=target[i]){
//         char s=source[i];
//         int t=target[i]-'a';
//         if(mymap[s][t]==INT_MAX){
//             return -1;
//         }
//         ans=ans+mymap[s][t];
//         }
//        }
//        return ans;
//     }
// };

// same solution i tried above passed 531 testcases understood tried my own but failed due to long long conversions and i used map insteadof 2d vector

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {
        int n = source.size();
        const long long INF = 1e15; // large enough to avoid overflow
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // initialize direct transformations
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // distance to itself = 0
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // Floyd–Warshall over all 26 letters
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // compute total cost
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                if (dist[u][v] == INF) return -1; // impossible
                ans += dist[u][v];
            }
        }

        return ans;
    }
};