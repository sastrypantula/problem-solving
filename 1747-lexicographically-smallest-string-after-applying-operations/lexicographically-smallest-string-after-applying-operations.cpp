class Solution {
public:
void revi (string& temp,int b){
    reverse(temp.begin(),temp.end());
    reverse(temp.begin(),temp.begin()+b);
    reverse(temp.begin()+b,temp.end());
}
    string findLexSmallestString(string s, int a, int b) {
        int n=s.length();
        queue<string>q;
        unordered_set<string>myset;
        q.push(s);
        string res=s;
        while(!q.empty()){
            string temp=q.front();
            q.pop();
            if(temp<res){
                res=temp;
                if(myset.count(res)==0){
                    myset.insert(res);
                }
            }
            for(int i=1;i<temp.length();i+=2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';
            }
            if(myset.count(temp)==0){
                myset.insert(temp);
                q.push(temp);
            }
            revi(temp,b);
            if(myset.count(temp)==0){
                myset.insert(temp);
                q.push(temp);
            }
        }
         return res;
    }
};