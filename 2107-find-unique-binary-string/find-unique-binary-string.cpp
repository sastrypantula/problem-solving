class Solution {
public:
 unordered_map<string,int> mymap;
 string ans;
 bool func(int i,int n,string temp){
    cout<<temp<<endl;
   if(i>=n){
    if(mymap[temp]==0){
        ans=temp;
        return true;
    }
    return false;
   }
    bool left=false;
    bool right=false;
     left=func(i+1,n,temp+'0');
    if(left==true){
        return true;
    }
    right=func(i+1,n,temp+'1');
    if(right==true){
        return true;
    }
   return left || right;

 }
    string findDifferentBinaryString(vector<string>& nums) {
       
        for(auto it:nums){
            mymap[it]++;
        }
        int n=nums[0].length();
      func(0,n,"");
       return ans;
    }
};