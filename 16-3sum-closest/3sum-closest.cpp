class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        for (int i = 0; i < ssize(nums) - 2; i++) {
    int left = i + 1, right = ssize(nums) - 1;
    while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (res == INT_MAX || abs(sum - target) < abs(res - target)) {
            res = sum;
        }
        if (sum > target) right--;
        else if (sum < target) left++;
        else return sum; 
    }
}
return res;
    }
};