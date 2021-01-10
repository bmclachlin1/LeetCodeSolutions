class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums(nums.size());
        int sum = 0;
        for (int i = 0; i < sums.size(); i++) {
            sum += nums[i];
            sums[i] = sum;
        }
        return sums;
    }
};