class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        int n=happiness.size();
        sort(happiness.begin(),happiness.end());
        int count=0;
        int i=n-1;
        while(count<k && i>=0){

            sum=sum+max(0,(happiness[i]-count));
            i--;
            count++;
        }
        return sum;
    }
};