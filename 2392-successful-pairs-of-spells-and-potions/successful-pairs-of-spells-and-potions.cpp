class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> result(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            long long num=spells[i];
            long long  low=0;
            long long high=m-1;
            while(low<=high){
                long long mid=(low+high)/2;
                if(num*potions[mid]>=success){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            result[i]=m-low;
        }
        return result;
    }
};