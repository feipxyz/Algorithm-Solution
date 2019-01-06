class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> dp(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                dp[i] = dp[i - 1] + 1;
        }

        for (int i = ratings.size() - 1; i > 0; i--)
        {
            if (ratings[i] < ratings[i - 1])
                dp[i - 1] = max(dp[i - 1], dp[i] + 1);
        }

        int sum = 0;
        for (auto a : dp)
        {
            sum += a;
        }
        return sum;
    }
};
