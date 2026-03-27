class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> temp=mat;
         k=k%n;
        for(int i=0;i<m;i++){
            if(i%2==0){
                rotate(temp[i].begin(),temp[i].begin()+k,temp[i].end());
            }
            else{
                rotate(temp[i].begin(),temp[i].end()-k,temp[i].end());
            }
        }
        return temp==mat;
    }
};