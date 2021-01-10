class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // sliding window approach
        int ans = 0, anchor = 0;
        // O(n) loop
        for (int i = 0; i < nums.size(); i++) {
            // Keep expanding window size until we reach end 
            // of an increasing continous subsequence
            if (i > 0 && nums[i-1] >= nums[i]) {
                anchor = i;
            }
            ans = max(ans, i - anchor + 1);
        }
        return ans;
    }
};