class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(n * 2);
        
        for (int i = 0; i < n*2; i++) {
            ans[i] = (i % 2 == 0) ? nums[i/2] : nums[n + i/2];
        }
        
        return ans;
    }
};