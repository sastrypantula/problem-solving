class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans=0;
        unordered_map<int,int> mymap;
        while(n>0){
            int rem=n%10;
            n=n/10;
            mymap[rem]++;
        }
        for(auto [it,count]:mymap){
            ans=ans+(it*count);
        }
        return ans;
    }
};