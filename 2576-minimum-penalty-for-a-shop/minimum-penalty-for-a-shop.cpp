class Solution {
public:
    int bestClosingTime(string customers) {
        unordered_map<char,int>left;
        unordered_map<char,int>right;
        for(char& ch:customers){
            right[ch]++;
        }
        int idx=INT_MIN;
        int penalty=INT_MAX;
        for(int i=0;i<customers.length();i++){
            char ch=customers[i];
            int count=0;
            if(ch=='N'){
                count=count+left['N']+right['Y'];
                left[ch]++;
                right[ch]--;
                
            }
            else{
                count++;
                left[ch]++;
                right[ch]--;
                count=count+left['N']+right['Y'];
            }
            cout<<count<<endl;
            if(count<penalty){
                idx=i;
                penalty=count;
            }
        }
        int c=left['N'];
        cout<<c<<endl;
        if(c<penalty){
            idx=customers.length();
        }
        if(idx==INT_MIN){
            return 0;
        }
        return idx;
    }
};