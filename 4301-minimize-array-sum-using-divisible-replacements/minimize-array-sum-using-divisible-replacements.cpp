class Solution {
public:
    
    long long minArraySum(vector<int>& nums) {
        long long sum=0;
        map<int,int> mymap;
        int maxi=INT_MIN;
        for(int it:nums){
            maxi=max(maxi,it);
            mymap[it]++;
        }
        for(auto [ele,count]:mymap){
            if(count==0){
                continue;
            }
            for(int i=ele;i<=maxi;i+=ele){
                if(mymap[i]!=0){
                    sum=sum+(1LL*ele*mymap[i]);
                    mymap[i]=0;
                }
            }
        }
        return sum;
    }
};