class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int k=0;k<n;k++){
            for(int i=k;i<n;i++){
                    int a=matrix[i][k];
                    matrix[i][k]=matrix[k][i];
                    matrix[k][i]=a;
                
            }
        }
      
        for(int k=0;k<n;k++){
            int i=0;
            int j=n-1;
            while(i<j){
                swap(matrix[k][i],matrix[k][j]);
                i++;
                j--;
            }
        }

         
    }
};