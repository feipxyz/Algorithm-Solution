class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (auto a : coins)
            {
                if (i - a >= 0)
                    dp[i] = min(dp[i], dp[i - a] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
