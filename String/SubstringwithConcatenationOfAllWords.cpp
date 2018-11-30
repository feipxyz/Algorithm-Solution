class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;
        unordered_map<string, int> mpWords;
        int m = words.size();
        int n = words[0].size();
        for (auto a : words)
        {
            mpWords[a]++;
        }

        for (int i = 0; i < s.size() - n * m + 1; i++)
        {
            unordered_map<string, int> mpCur;
            int j = 0;
            for (; j < m; j++)
            {
                string strTmp = s.substr(i + n * j, n);
                if (mpWords.count(strTmp) == 0)
                    break;

                mpCur[strTmp]++;
                if (mpCur[strTmp] > mpWords[strTmp])
                    break;
            }

            if (j == m)
                res.push_back(i);
        }
        return res;
    }
};
