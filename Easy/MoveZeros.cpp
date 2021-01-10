class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Approach: bring all non-zero elements to the front
        
        //Keep track of where we saw our last non-zero element
        int lastNonZeroIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // if not a zero then we place non-zero element
            // at position lastNonZeroIndex and advance lastNonZeroIndex
            // by 1
            if (nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i];
            }
        }
        
        for (int i = lastNonZeroIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};