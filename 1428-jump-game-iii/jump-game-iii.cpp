class Solution {
public:

bool func(int i,int n,vector<int>& arr,vector<bool>& visited){
    if(i<0 || i>=n){
        return false;
    }
if(arr[i]==0){
    return true;
}
bool left=false;
bool right=false;

if(visited[i]==false){
    visited[i]=true;
 left=func(i-arr[i],n,arr,visited);
 right=func(i+arr[i],n,arr,visited);
}
visited[i]=true;
return left || right;

}
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
         vector<bool> visited(n,false);
        if(arr[start]==0){
            return true;
        }
        int left=start-arr[start];
        int right=start+arr[start];
        return func(left,n,arr,visited) || func(right,n,arr,visited);
    }
};