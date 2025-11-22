class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int count=0;
         cout<<"I am outside the loop"<<endl;
         for(int it:nums){
               cout<<"I am inside the loop"<<endl;
            if(it%3==0){
                cout<<"I am inside the continue loop"<<endl;
                continue;
            }
            else if(((it-1)%3==0) || ((it+1)%3==0)){
                cout<<"I am inside the one loop"<<endl;
                count+=1;
            }
            else if(((it-2)%3==0) || ((it+2)%3==0)){
                cout<<"I am inside the two loop"<<endl;
                count+=2;
            }
         }
         return count;
    }
};