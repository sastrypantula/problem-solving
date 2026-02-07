class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> prefix(n,0); // will store the left b counts
        vector<int> suffix(n,0); // will store the right a counts
        // see we have problem with the (b,a) only so traversing through all the indices and remove that pairs and check the min possible 
        for(int i=1;i<n;i++){
            if(s[i-1]=='b'){
                prefix[i]=prefix[i-1]+1;
            }
            else{
                prefix[i]=prefix[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='a'){
                suffix[i]=suffix[i+1]+1;
            }
            else{
                suffix[i]=suffix[i+1];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,prefix[i]+suffix[i]);
        }
        return ans;
    }
};