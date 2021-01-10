class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, i = 0, j = height.size() - 1, currArea;
        while (i < j) {
            if (min(height[i], height[j]) * (j - i) > max) {
                max = min(height[i], height[j]) * (j - i);
            }
            (min(height[i], height[j]) == height[i]) ? i++ : j--;
        }
        return max;
    }
};