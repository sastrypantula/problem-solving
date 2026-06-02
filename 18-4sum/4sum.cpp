class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> myset;

    void twopointer(int low, int high,
                    vector<int>& nums,
                    long long target2) {

        int i = low + 1;
        int j = high - 1;

        while(i < j) {

            long long sum =
                (long long)nums[i] + nums[j];

            if(sum == target2) {

                vector<int> temp = {
                    nums[low],
                    nums[i],
                    nums[j],
                    nums[high]
                };

                sort(temp.begin(), temp.end());

                if(myset.count(temp) == 0) {
                    myset.insert(temp);
                    ans.push_back(temp);
                }

                i++;
                j--;
            }
            else if(sum < target2) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums,
                                int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i <= n - 4; i++) {

            for(int k = n - 1; k > i + 2; k--) {

                long long t =
                    (long long)target
                    - nums[i]
                    - nums[k];

                twopointer(i, k, nums, t);
            }
        }

        return ans;
    }
};