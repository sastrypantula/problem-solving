class Solution {
public:
int n;
bool func(int i,vector<int>& arr,int target,vector<bool>& visited){
    if(i<0 || i>=n){
        return false;
    }
    if(arr[i]==target){
        return true;
    }
    bool left=false;
    if(i-arr[i]>=0 && visited[i-arr[i]]==false){
    visited[i]=true;
    left=func(i-arr[i],arr,target,visited);
    }
    bool right=false;
    if(i+arr[i]<n && visited[i+arr[i]]==false){
        visited[i]=true;
    right=func(i+arr[i],arr,target,visited);
    }
    return left||right;
}
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        vector<bool> visited(n,false);
        return func(start,arr,0,visited);
    }
};