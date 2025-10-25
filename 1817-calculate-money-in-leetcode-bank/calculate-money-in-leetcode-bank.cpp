class Solution {
public:
    int totalMoney(int n) {
        // int res=0;
        // int ans=0;
        // int mon=0;
        // int count=1;
        // while(count<=n){
        //    if((count-1)%7==0){
        //     res=mon+1;
        //     mon++;
        //    }
        //    else{
        //     res=res+1;
        //    }
        //    ans=ans+res;
        //    cout<<res<<" ";
        //    count++;
        // }
        // return ans;

    int terms = n/7; //Weeks

        int first = 28;
        int last  = 28 + (terms - 1) * 7; //AP formula for n-th term

        int result = terms * (first + last) / 2; //Sum of nth terms in an AP


        //remaining days
        int remain = n%7;
        int first_term = (1 + terms);
        int last_term  = first_term + remain - 1;
        result += remain * (first_term + last_term) / 2;

        return result;
    }
};