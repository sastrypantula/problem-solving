class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
       int n=grid.size();
       vector<int> temp(n,-1);
       for(int i=0;i<n;i++){
        int count=0;
        for(int j=n-1;j>=0;j--){
            if(grid[i][j]==1){
                break;
            }
            else{
                count++;
            }
        }
        temp[i]=count;
       } 
//        for(int it:temp){
//     cout<<it<<" ";
// }
// cout<<endl;
       int ans=0;
       vector<int> copy=temp;
       sort(copy.begin(),copy.end(),greater<int>());
       for(int i=0;i<=copy.size()-2;i++){
        if(copy[i]<n-i-1){
            return -1;
        }
       }
    
    for(int i=0;i<n;i++){
        int want=n-i-1;
        if(temp[i]>=want){
            continue;
        }
        else{
            int j=i;
            while(j<n && temp[j]<want){
                j++;
            }
            while(j!=i && j-1>=0){
                swap(temp[j],temp[j-1]);
                ans++;
                j--;
            }
        }
    }
return ans;
       
    }
};