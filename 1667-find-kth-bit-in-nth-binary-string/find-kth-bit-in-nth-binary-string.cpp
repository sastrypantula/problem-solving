class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        int i=1;
        while(i<n){
            string temp=s;
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++){
                temp[j]=('1'-temp[j])+'0';
            }
           
            s=s+'1'+temp;
            // cout<<s<<endl;
            i++;
        }
        // cout<<s<<endl;
        cout<<i<<endl;
        return s[k-1];
    }
};