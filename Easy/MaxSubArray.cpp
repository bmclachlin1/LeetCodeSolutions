class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // max subarray sum found so far
        int maxSum = INT_MIN;
        // current subarray sum
        int currSum = 0;
        
        for (int n : nums) {
            // negative prefix won't help to get maximum
            if (currSum < 0) {
                currSum = 0;
            }
            // update curr
            currSum += n;
            // update max
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};