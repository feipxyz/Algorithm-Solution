class Solution {
public:
    unordered_map<string, vector<string>> mpword;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (mpword.count(s) != 0)
            return mpword[s];
        if (s.size() == 0)
            return {""};
        vector<string> res;
        for (auto word : wordDict)
        {
            if (s.substr(0, word.length()) != word)
                continue;
            vector<string> remain = wordBreak(s.substr(word.length()), wordDict);
            for (auto a : remain)
            {
                res.push_back(word + (a.empty() ? "" : " ") + a);
            }
        }
        mpword[s] = res;
        return res;
    }
};
