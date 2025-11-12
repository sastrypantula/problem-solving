class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int dist=INT_MAX;
        unordered_map<int,set<int>>mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]].insert(i);
        }
        for(auto [key,value]:mymap){
            // if(value.size()>=3){
                // auto it=value.begin();
                // int a=*it;
                // it++;
                // int b=*it;
                //  it++;
                // int c=*it;
                // int t=abs(a-b)+abs(b-c)+abs(c-a);
                // dist=min(dist,t);
                 if (value.size() >= 3) {
        auto it1 = value.begin();
        auto it2 = std::next(it1);
        auto it3 = std::next(it2);

        while (it3 != value.end()) {
            int a = *it1;
            int b = *it2;
            int c = *it3;

            int t = abs(a - b) + abs(b - c) + abs(c - a);
            dist = std::min(dist, t);

            ++it1;
            ++it2;
            ++it3;
        }
    }

            
        }
        if(dist==INT_MAX){
            return -1;
        }
        return dist;
    }
};