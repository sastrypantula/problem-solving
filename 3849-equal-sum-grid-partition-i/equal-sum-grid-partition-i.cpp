// class Solution {
// public:
//     bool canPartitionGrid(vector<vector<int>>& grid) {
        
//         int m=grid.size();
//         int n=grid[0].size();

        
//         long long totalsum=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
        
//                 totalsum+=grid[i][j];
//             }
//         }
      


//         long long curr=0;
//          for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 curr=curr+grid[i][j];
//             }
//             if(curr==totalsum-curr)return true;
//          }
//         curr=0;
//         for(int j=0;j<n;j++){
//         for(int i=0;i<m;i++){
//             curr=curr+grid[i][j];
//         }
//         if(curr==totalsum-curr)return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<long long>rows(m,0);
        vector<long long>cols(n,0);
        long long totalsum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rows[i]=rows[i]+grid[i][j];
                totalsum+=grid[i][j];
            }
        }
        if(totalsum%2!=0){
            return false;
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                cols[j]=cols[j]+grid[i][j];
            }
        }

        long long curr=0;
        for(int i=0;i<m-1;i++){
           curr=curr+rows[i];
          int want=totalsum-curr;
          if(curr==want)return true;
        }
        curr=0;
        for(int j=0;j<n-1;j++){
             curr=curr+cols[j];
            long long want=totalsum-curr;
            if(curr==want)return true;
        }
        return false;
    }
};