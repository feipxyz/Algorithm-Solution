class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++)
        {
            dp[i] = i;
            for (int j = 0; j <= i; j++)
            {
                if (s[i] == s[j] && (j + 1 > i - 1 || pal[j + 1][i - 1]))
                {
                    dp[i] = j == 0 ? 0 : min(dp[i], dp[j - 1] + 1);
                    pal[j][i] = true;
                }
            }
        }
        return dp[n - 1];
    }
};
