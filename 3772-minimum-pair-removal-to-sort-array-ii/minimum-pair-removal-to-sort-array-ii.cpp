// very good problem learned a lot 
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // storing in another vector as sum of two nums can exceed the int 
        int n=nums.size();
        vector<long long> temp(n);
        int badpairs=0;
        int ans=0;
        set<pair<long long,int>> myset; 
        for(int i=0;i<n;i++){
            temp[i]=nums[i];
        }
        for(int i=0;i<n-1;i++){
            if(temp[i+1]<temp[i]){
                badpairs++;
            }
            myset.insert({temp[i]+temp[i+1],i});
        }
        vector<int>prevIndex(n);
        vector<int>nextIndex(n);
        for(int i=0;i<n;i++){
            prevIndex[i]=i-1;
            nextIndex[i]=i+1;
        }
        while(badpairs>0){
            auto it=myset.begin();
          
            int first=it->second;// (x,a,b,c) if we take a+b as min sum then a is first, b is second x is first_left and c is second_right
              
            int second=nextIndex[first];
            int first_left=prevIndex[first];
            int second_right=nextIndex[second];
            myset.erase(myset.begin());
            if(temp[first]>temp[second]){
                badpairs--;
            }
            if(first_left>=0){
                if(temp[first_left]>temp[first] && temp[first_left]<=temp[first]+temp[second]){
                    badpairs--;
                }
                if(temp[first_left]<=temp[first] && temp[first_left]>temp[first]+temp[second]){
                    badpairs++;
                }
                myset.erase({temp[first_left]+temp[first],first_left});
                myset.insert({temp[first_left]+temp[first]+temp[second],first_left});
             
            }
             if(second_right<n){
                if(temp[second_right]<temp[second] && temp[second_right]>=temp[first]+temp[second]){
                    badpairs--;
                }
                if(temp[second]<=temp[second_right] && temp[second_right]<temp[first]+temp[second]){
                    badpairs++;
                }
                myset.erase({temp[second]+temp[second_right],second});
                myset.insert({temp[second_right]+temp[first]+temp[second],first});
                 prevIndex[second_right]=first;
            }
               nextIndex[first] = second_right;
               temp[first] =temp[first]+temp[second];
               ans++;
        }
        return ans;
    }
};