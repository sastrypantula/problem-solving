class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int count=0;
        int count_zeros=0;
        int ni=-1;
        int nj=-1;
        long long  sum=0;
        long long  ele=LLONG_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    count_zeros++;
                }
                if(matrix[i][j]<0){
                    count++;

                }
                ele=min(ele,(long long)abs(matrix[i][j]));
                sum=sum+abs(matrix[i][j]);
            }
        }
        
        if(count==0 || count%2==0 || (count%2==1 && count_zeros>0)){
            return sum;
        }
        cout<<sum<<" "<<ele<<endl;
        return sum-2*ele;
    }
};