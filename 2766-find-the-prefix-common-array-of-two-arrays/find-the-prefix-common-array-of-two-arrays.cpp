class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mymap1;
        unordered_map<int,int> mymap2;
        int n=A.size();
        vector<int> ans(n,0);
        if(A[0]==B[0]){
            ans[0]=1;
        }
        mymap1[A[0]]++;
        mymap2[B[0]]++;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1];
            int t=0;
            if(A[i]==B[i]){
                t=1;
            }
            else{
                if(mymap1.count(B[i])){
                    t++;
                }
                if(mymap2.count(A[i])){
                    t++;
                }
            }
            ans[i]+=t;
            mymap1[A[i]]++;
            mymap2[B[i]]++;
        }
        return ans;
    }
};