class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
       
        for(int i=0;i<n;i++){
             vector<int> temp(26,0);
            for(int j=i;j<n;j++){
                int t=s[j]-'a';
                temp[t]++;
                int a=-1;
                bool flag=true;
                for(int it:temp){
                  if(it!=0 && a==-1){
                     a=it;
                  }
                  else if(it!=0){
                    if(it!=a){
                        flag=false;
                        break;
                    }
                  }
                }
               if(flag){
                ans=max(ans,j-i+1);
               }
            }
        }
        return ans;
    }
};