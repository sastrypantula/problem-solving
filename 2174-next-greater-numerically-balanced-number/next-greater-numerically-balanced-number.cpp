class Solution {
public:
bool func(int n){
    vector<int> mymap(10,0);
    int temp=n;
    while(temp>0){
        int rem=temp%10;
        temp=temp/10;
        mymap[rem]++;
    }
    temp=n;
    while(temp>0){
        int rem=temp%10;
        if(mymap[rem]!=rem){
            return false;
        }
        temp=temp/10;
    }
return true;
}
    int nextBeautifulNumber(int n) {
        int digits=0;
        // int temp=n+1;
        // while(temp>0){
        //     temp=temp/10;
        //     digits++;
        // }
        // int maxdigi=digits+1;
        // int s=maxdigi;
        // cout<<maxdigi<<endl;
        // int count=0;
        // while(count<digits){
        //     maxdigi=(maxdigi*10)+s;
        //     // cout<<maxdigi<<endl;
        //     count++;
        // }
        // rather than that take the 10 power6 after smallest balanced one 
       int  maxdigi=1224444;
      int low=n+1;
      int high=maxdigi;
      int ans=maxdigi;
      for(int i=low;i<=high;i++){
        if(func(i)){
            return i;
        }
      }
      return ans;
    }

};