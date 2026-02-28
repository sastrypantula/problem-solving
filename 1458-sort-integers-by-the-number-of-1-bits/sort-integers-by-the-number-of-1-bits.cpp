class Solution {
public:
  static bool func(int a,int b){
    int count1=0;
    int count2=0;
    int temp1=a;
    int temp2=b;
    while(a>0){
        int rem=a%2;
        if(rem==1){
            count1++;
        }
        a=a/2;
    }
     while(b>0){
        int rem=b%2;
        if(rem==1){
            count2++;
        }
        b=b/2;
    }
    if(count1==count2){
        return temp1<temp2;
    }
    return count1<count2;

}
    vector<int> sortByBits(vector<int>& arr) {
      
        sort(arr.begin(),arr.end(),func);
        return arr;
    }
};