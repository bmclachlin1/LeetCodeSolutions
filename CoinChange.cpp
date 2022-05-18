class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0; // minimum number of coins to get to 0 is 0
        for (int a = 1; a <= amount; a++) {
            for (int c : coins) {
                // if we take the current coin and amount is still greater than 0
                if (a - c >= 0) {
                    // the solution is either the current solution OR
                    // we take coin c (1 number of coins) plus the solution
                    // to dp[a - c]
                    dp[a] = min(dp[a], 1 + dp[a - c]);
                }
                
            }
        }
        
        return (dp[amount] != amount + 1) ? dp[amount] : -1;
    }
};