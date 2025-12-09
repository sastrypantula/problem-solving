class Solution {
public:
int MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>left;
        unordered_map<int,int>total;
        for(int x:nums){
            total[x]++;
        }
        int ans=0;
        for(int x:nums){
            // int target=x*2;
            // if(left.count(target)>=1 && total.count(target)>=1){
            // int leftside=left[target];
            // int rightside=total[target];
            // ans+=((leftside*rightside)%MOD);
            // }
            // left[x]++;
            // total[x]--;
             total[x]--;  // remove current
    long long leftc = left[2 *x];
    long long rightc = total[2 * x];
    ans = (ans + (leftc* rightc) % MOD) % MOD;
    left[x]++;

        }
        return ans;
    }
};