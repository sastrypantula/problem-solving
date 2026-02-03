class Solution {
public:
vector<vector<int>> result;
void func(int i,vector<int>& temp,vector<int>& arr,int k,int n,int sum){
if(temp.size()==k){
    if(sum==n){
        result.push_back(temp);
    }
    return;
}
if(i==arr.size()){
    if(sum==n && temp.size()==k){
        result.push_back(temp);
        return;
    }
    return;
}
temp.push_back(arr[i]);
func(i+1,temp,arr,k,n,sum+arr[i]);
temp.pop_back();
func(i+1,temp,arr,k,n,sum);

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<int> temp;
         func(0,temp,arr,k,n,0);
         return result;
    }
};