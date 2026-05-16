class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int i=0;
        int j=cols-1;
        int k1=-1;
        int k;
        for(k=0;k<rows;k++){
            if(matrix[k][0]<=target && target<=matrix[k][j]){
                   k1=k;
                   break; 
            }
        }
        cout<<k1<<endl;
        if(k1==-1){
            return false;
        }
        while(i<=j){
          int mid=(i+j)/2;
          if(matrix[k1][mid]==target){
            return true;
          }
          else if(matrix[k1][mid]>target){
            j=mid-1;
          }
          else{
            i=mid+1;
          }
        }
        return false;
    }
};