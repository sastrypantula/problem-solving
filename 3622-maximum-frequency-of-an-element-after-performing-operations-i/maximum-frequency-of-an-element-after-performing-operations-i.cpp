class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // this code is working for 453 testcases worked very hard to solve it good question to revise again.....................


        //  // taking the prefix sum to know the count of the numbers lying in the range its a best technique 
        // if(nums.size()==1 || k==0){
        //  return 1;
        // }
        //  sort(nums.begin(),nums.end());
        //  int maxi=INT_MIN;
        //  for(int it:nums){
        //     maxi=max(maxi,it);
        //  }
        //  vector<int> prefixsums(maxi+k+1,0);
        //  vector<int>prefixsum(maxi+k+1,0);
        //  for(int it:nums){
        //     prefixsums[it]++;
        //  }
        //  for(int it:prefixsums){
        //     cout<<it<<" ";
        //  }
        //  cout<<endl;
        //  for(int i=1;i<prefixsums.size();i++){
        //     prefixsum[i]=prefixsums[i]+prefixsum[i-1]; // calculating the cum sum to get the numbers blw the range
        //  }
        //  int res=0;
        //  // apply bin search to search efficiently without traversing 
        //  int low=0;
        //  int high=nums.size()-1;
        //  while(low<=high){
        //     int mid=(low+high)/2;
        //     int num=nums[mid];
        //     int lowRange=num-k;
        //     int highRange=num+k;

        //     int count=prefixsum[highRange]-(lowRange>=0?prefixsum[lowRange]:0);
        //     int reqops=count-prefixsums[num];
        //     int canbeconverted=min(reqops,numOperations);
        //     cout<<"canbeconverted : "<<canbeconverted<<endl;
        //     int t=canbeconverted+prefixsums[num];
        //     cout<<"t : "<<t<<endl;
        //     res=max(res,t);
        //     cout<<res<<endl;
        //     if(res<=t){
        //         low=mid+1;
        //     }
        //     else{
        //         high=mid-1;
        //     }
        //  }
        //  return res;

        // .............  copied solution 

          int maxEl = *max_element(begin(nums), end(nums)) + k;

        vector<int> freq(maxEl + 1, 0);

        for(int &num : nums) {
            freq[num]++;
        }

        //cumulative sum of frequenceis
        for(int i = 1; i <= maxEl; i++) {
            freq[i] += freq[i-1];
        }

        int result = 0;
        for(int target = 0; target <= maxEl; target++) {
            if(freq[target] == 0)
                continue;
            
            int leftNum  = max(0, target-k); //l
            int rightNum = min(maxEl, target+k); //r

            int totalCount  = freq[rightNum] - (leftNum > 0 ? freq[leftNum-1] : 0);

            int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);

            int needConversion = totalCount - targetCount;

            int maxPossibleFreq = targetCount + min(needConversion, numOperations);

            result = max(result, maxPossibleFreq);
        }

        return result;
       
      
    }
};
   