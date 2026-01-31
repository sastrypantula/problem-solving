class Solution {
public:
vector<string> result;
void chk(string temp,int n,int i,int j){
    if(temp.length()==2*n && i==n && j==n){
        result.push_back(temp);
        return;
    }
    if(temp.length()==0){
        chk(temp+"(",n,i+1,j);
    }
    else{
        if(i<n) chk(temp+"(",n,i+1,j);
        if(!temp.empty() && j<i) chk(temp+")",n,i,j+1);

    }
}
    vector<string> generateParenthesis(int n) {
        string temp="";
        chk(temp,n,0,0);
        return result;
    }
};