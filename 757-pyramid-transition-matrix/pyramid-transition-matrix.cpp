class Solution {
public:
unordered_map<string,vector<char>>mymap;
unordered_map<string,bool>dp;
bool solve(string curr,int i,string next){
    if(curr.length()==1){
        return true;
    }
    string key=curr+"-"+to_string(i)+"-"+next;
    if(i==curr.length()-1){
        return dp[key]=solve(next,0,"");
    }
    
    if(dp.count(key)){
        return dp[key];
    }
    string pair = string(1, curr[i]) + string(1, curr[i+1]);
    if(mymap.find(pair)==mymap.end()){
        return dp[key]=false;
    }
    vector<char> vec=mymap[pair];
    for(char& ch:vec){
       next.push_back(ch);
       if(solve(curr,i+1,next)){
        return dp[key]=true;
       }
       next.pop_back();
    }
    return dp[key]=false;
}

    bool pyramidTransition(string bottom, vector<string>& allowed) {  
        for(auto& s:allowed){
            mymap[s.substr(0,2)].push_back(s[2]);
        }
        return solve(bottom,0,"");
    }
};