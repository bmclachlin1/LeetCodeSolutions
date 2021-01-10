class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (char c : stones) {
            if (jewels.find(c) != string::npos) {
                ans++;
            }
        }
        return ans;
    }
};