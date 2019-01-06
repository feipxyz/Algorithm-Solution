class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, string> mpWord;
        for (auto a : wordDict)
            mpWord[a] = a;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                string sub = s.substr(j, i - j);
                if (dp[j] && mpWord.find(sub) != mpWord.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
