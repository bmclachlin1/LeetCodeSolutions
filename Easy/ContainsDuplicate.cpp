class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> map;
        
        for (int n : nums) {
            map[n]++;
        }
        
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->second > 1) {
                return true;
            }
        }
        
        return false;
    }
};