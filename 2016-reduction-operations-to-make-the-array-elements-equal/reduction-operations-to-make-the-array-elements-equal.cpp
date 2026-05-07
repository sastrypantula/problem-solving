class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mymap;
        for(int it:nums){
            mymap[it]++;
        }
        int ans=0;
        auto it = mymap.rbegin(); 
        while(true) {
            auto next = it;
            ++next; 
            if(next == mymap.rend()) break;

            int b = it->first;
            int count2 = it->second;
            int a = next->first;
            int count1 = next->second;
          
            mymap[a]=mymap[a]+count2;
            ans += count2;
            // cout<<"largest "<<b<<endl;
            // cout<<"Count "<<count2<<endl;
            // cout<<ans<<endl;
            it = next; 
        }

        return ans;
    }
};