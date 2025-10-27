class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].size();
        vector<bool>beam(m,false);
        vector<int>devices(m,0);
        for(int i=0;i<m;i++){
            bool flag=false;
            for(char it:bank[i]){
                if(it=='1'){
                    devices[i]++;
                    flag=true;
                }
            }
            if(flag){
                beam[i]=true;
            }
        }
        for(int i=0;i<m;i++){
            cout<<beam[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<m;i++){
            cout<<devices[i]<<" ";
        }
        int ans=0;
        for(int i=0;i<m;i++){
         int count1=devices[i];
         for(int j=i+1;j<m;j++){
            if(devices[j]>=0 && (beam[j-1]==false || j-1==i)){
                ans=ans+(count1*devices[j]);
            }
            else{
                break;
            }
         }

        }
        return ans;
    }
};