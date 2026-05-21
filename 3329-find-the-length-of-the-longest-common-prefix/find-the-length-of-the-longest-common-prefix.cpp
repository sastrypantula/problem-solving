class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        unordered_map<string,int> mymap;
        for(int i=0;i<arr1.size();i++){
             string s=to_string(arr1[i]);
             string temp="";
             int j=0;
             while(j<s.length()){
                temp=temp+s[j];
                mymap[temp]++;
                j++;
             }
        }
        int ans=INT_MIN;
        for(int i=arr2.size()-1;i>=0;i--){
            string s=to_string(arr2[i]);
            while(s.length()>0){
                if(mymap.count(s)){
                    ans=max(ans,(int)s.length());
                    break;
                }
                s.pop_back();
            }
        } 
        if(ans==INT_MIN){
            return 0;
        } 
        return ans;
    }
};