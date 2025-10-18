class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // unordered_set<int>myset;
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        //Tried Greedily+ Brute  but Failed in some test case 

    //     for(int i=0;i<n;i++){
    //       if(myset.find(nums[i])==myset.end()){
    //         myset.insert(nums[i]);
    //       }
    //       else{
    //         if(myset.find(nums[i]+k)==myset.end()){
    //             for(int j=1;j<=k;j++){
    //                 if(myset.find(nums[i]+j)==myset.end()){
    //                     myset.insert(nums[i]+j);
    //                     break;
    //                 }
    //             }
    //         }
    //       else{
    // for(int j = k; j >= 1; j--) {
    //     if(myset.find(nums[i]-j) == myset.end()) {
    //         myset.insert(nums[i]-j);
    //         break;
    //     }
    // }

    //         }
    //       }
    //     }
    //     for(int it:myset){
    //         cout<<it<<" ";
    //     }

    // optimise Greedy assigining the last ki min value after operation so that every time we get the lowest possible

   
        int n = nums.size();

        sort(begin(nums), end(nums));

        int count = 0;

        int prev = INT_MIN;

        for(int i = 0; i < n; i++) {
            int minVal = nums[i] - k;

            if(prev < minVal) {
                //nums[i] = nums[i]-k;
                prev = minVal;
                count++;
            } else if(prev < nums[i] + k) {
                //nums[i] = prev+1;
                prev = prev+1;
                count++;
            }
        }

        return count;
    }
};