class Solution {
public:
    void check(int time,string s,vector<int>& offline,vector<int>& ans){
        if(s=="HERE"){
           for(int i=0;i<offline.size();i++){
            if(offline[i]==0 || offline[i]+60<=time){
                ans[i]++;
            }
          }
        }
        else if(s=="ALL"){
          for(int i=0;i<ans.size();i++){
            ans[i]++;
          }
        }
        else{
            vector<int> ids;
            int n=s.length();
            string num = "";
for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
        ids.push_back(stoi(num));
        num = "";
    } else if (isdigit(s[i])) {
        num += s[i];
    }
}
if (!num.empty()) ids.push_back(stoi(num));

            // ids.push_back(s[n-1]-'0');
            for(int id:ids){
                
                    ans[id]++;
                
            }
        }
        for(int it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
   
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        auto lambda=[](vector<string>& vec1,vector<string>& vec2){
    int t1=stoi(vec1[1]);
    int t2=stoi(vec2[1]);
    if(t1==t2){
       return vec1[0][0]>vec2[0][0]; // O>M
    }
    else{
        return t1<t2;
    }
};
        vector<int>offline(numberOfUsers,0); 
        vector<int>ans(numberOfUsers,0);
        sort(events.begin(),events.end(),lambda);
       for (int i = 0; i < events.size(); i++) {
    cout << events[i][0] << " " 
         << events[i][1] << " " 
         << events[i][2] << endl;
}
        for(int i=0;i<events.size();i++){
            string s=events[i][0];
            int time=stoi(events[i][1]);
            string idnums=events[i][2];
            if(s=="MESSAGE"){
                check(time,idnums,offline,ans);
            }
            else{
                int t=stoi(idnums);
                offline[t]=time;
            }
        }
        return ans;

    }
};