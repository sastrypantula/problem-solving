class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
         vector<int> ans;
        for(int& num:nums){
            if(num==2){
                ans.push_back(-1);
                continue;
            }
            bool flag=false;
            for(int i=1;i<32;i++){
                if((num & (1<<i))>0){
                    continue;
                }
                else{
                    flag=true;
                    cout<<"i value for "<<num<<" is "<<i-1<<endl;
                    int t=(num)^(1<<(i-1));
                    ans.push_back(t);
                    break;
                }
            }
            if(flag==false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};