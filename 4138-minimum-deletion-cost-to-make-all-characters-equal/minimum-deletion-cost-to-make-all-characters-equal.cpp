class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long> mymap;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            mymap[ch]=mymap[ch]+cost[i];
        }
        if(mymap.size()==1){
            return 0;
        }
        long long ans=LONG_MAX;
        for(char chr='a';chr<='z';chr++){
            long long cost=0;
            for(auto [ch,val]:mymap){
                if(ch!=chr){
                cost=cost+val;
                }
            }
            ans=min(ans,cost);
        }
return ans;
    }
};