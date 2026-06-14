class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        unordered_set<int> myset(nums.begin(),nums.end());
        if(myset.size()==n){
            return 1;
        }
        for(int i=0;i<n;i++){
            unordered_map<int,int> mymap;
            unordered_map<int,int> freq;
            for(int j=i;j<n;j++){
                if(mymap.find(nums[j])==mymap.end()){
                    mymap[nums[j]]++;
                    freq[1]++;
                }
                else{
                     freq[mymap[nums[j]]]--;
                    if(freq[mymap[nums[j]]]==0){
                        freq.erase(mymap[nums[j]]);
                    }
                    mymap[nums[j]]++;
                    freq[mymap[nums[j]]]++;
                }

                if(freq.size()==1 && mymap.size()==1){
                     ans=max(ans,j-i+1);
                }
                else if(freq.size()==2){
                    int count1=-1;
                    int count2=-1;
                    for(auto it:freq){
                        if(count1==-1){
                        count1=it.first;
                        }
                        else{
                        count2=it.first;
                        }
                    }
                    if(count1>count2 && count1==2*count2){
                        cout<<"i : "<<i<<"j "<<j<<endl;
                        ans=max(ans,j-i+1);
                    }
                    else if(count2>count1 && count2==2*count1){
                          cout<<"i : "<<i<<"j "<<j<<endl;
                        ans=max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};