class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        
        vector<bool> candyKids(candies.size());
        
        for (int i = 0; i < candies.size(); i++) {
            (candies[i] + extraCandies >= max) ? candyKids[i] = true : candyKids[i] = false;
        }
        
        return candyKids;
    }
};