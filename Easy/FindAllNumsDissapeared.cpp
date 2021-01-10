class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> solution;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if (mp.find(i) == mp.end()) {
                solution.push_back(i);
            }
        }
        
        return solution;
    }
};