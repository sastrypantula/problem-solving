class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        int result=0;
        vector<int> elements;
        for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        elements.push_back(grid[i][j]);
       }
        }
        sort(elements.begin(),elements.end());
        int sizes=elements.size();
        int index=-1;
         if(sizes%2==0){
         index=(sizes/2)-1;
         }
         else{
            index=(int)(sizes/2);
         }
         int target=elements[index];
         for(int i=0;i<sizes;i++){
           int temp = abs(elements[i] - target);
            if (temp % x != 0) {
                return -1;  
            }
            result += temp / x;
         }
         return result;
    }
};