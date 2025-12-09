class Solution {
public:
int MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
    //     int n=nums.size();
    //     unordered_map<int,int>left;
    //     unordered_map<int,int>total;
    //     for(int x:nums){
    //         total[x]++;
    //     }
    //     int ans=0;
    //     for(int x:nums){
            
    //          total[x]--;  
    // long long leftc = left[2 *x];
    // long long rightc = total[2 * x];
    // ans = (ans + (leftc* rightc) % MOD) % MOD;
    // left[x]++;

    //     }
    //     return ans;


    ////// optimised one

    unordered_map<int,int>icount;
    unordered_map<int,int>jcount;
    int ans=0;
    for(int x:nums){
        if(x%2==0){
            ans=(ans+jcount[x/2])%MOD;
        }
        jcount[x]=(jcount[x]+icount[x*2])%MOD;
        icount[x]++;
    }
    return ans;
    }
};