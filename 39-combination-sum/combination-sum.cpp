class Solution {
public:
 vector<vector<int>> result;
void func(int i,vector<int>& candidates,vector<int>& temp,int target){
    if(i==candidates.size()){
        if(target==0){
            result.push_back(temp);
        }

    return;
}
if(candidates[i]<=target){
    temp.push_back(candidates[i]);
    func(i,candidates,temp,target-candidates[i]);
    temp.pop_back();
}
func(i+1,candidates,temp,target);


}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> temp;
            func(0,candidates,temp,target);
        return result;
    }
};