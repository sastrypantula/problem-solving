class Solution {
public:
int MOD=1e9+7;
    int countPermutations(vector<int>& complexity) {
        // set<int>myset;
        // int n=complexity.size();
        // bool mainflag=true;
        // myset.insert(complexity[0]);
        // for(int i=1;i<complexity.size();i++){
        //     bool flag=false;
        //     int t=complexity[i];
        //     for(auto it=myset.rbegin();it!=myset.rend();it++){
        //         if(*it<t){
        //             flag=true;
        //             break;
        //         }
        //     }
        //     if(flag==false){
        //         return 0;
        //     }
        //     myset.insert(t);
        // }
        // long long fact = 1;
        // for (int i = 1; i < n; i++) {
        //     fact = (fact * i) % MOD;  
        // }

        // return (int)fact;
        long long res=1;
    int n=complexity.size();
    for(int i=1;i<n;i++){
        if(complexity[i]<=complexity[0]) return 0;
        res*=i;
        res=res%MOD;
    }
    return res;
    }
};